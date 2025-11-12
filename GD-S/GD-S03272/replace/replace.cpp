#include<bits/stdc++.h>
using namespace std;
int n,q;
string sp[200005],sq[200005],sx,sy;
int main(){
	ifstream read("replace.in");
	ofstream write("replace.out");
	read>>n>>q;
	for(int i=1;i<=n;i++){
		read>>sp[i]>>sq[i];
	}
	while(q--){
		read>>sx>>sy;
		int l=0,r=0;
		int ans=0;
		for(int i=0;i<(int)sx.length();i++){
			if(sx[i]==sy[i]){
				continue;
			}
			else{
				if(l==0&&r==0){
					l=r=i;
				}
				else{
					r=i;
				}
			}
			for(int j=1;j<=n;j++){
				bool b=0;
				if((int)sp[j].length()==r-l+1){
					for(int k=0;k<=r-l+1;k++){
						if(!(sp[j][k]==sx[l+k]&&sq[j][k]==sy[l+k])){
							b=1;break;
						}
					}
				}
				if(!b){
					ans++;
				}
			}
		}
		write<<ans<<endl;
	} 
	return 0;
}
