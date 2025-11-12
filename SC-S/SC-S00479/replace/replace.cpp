#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[2][200005],t[2];
char c;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		int sum=0;
		if(t[0].size()==t[1].size()){
			int l,r;
			for(int j=t[0].size()-1;j>=0;j--){
				if(t[0][j]!=t[1][j]){
					r=j;
					break;
				}
			}
			for(int j=0;j<t[0].size();j++){
				if(t[0][j]!=t[1][j]){
					l=j;
					break;
				}
			}
			for(int j=0;j<=l;j++){
				for(int k=1;k<=n;k++){
					if(j+s[0][k].size()<=r){
						continue;
					}
					int x=0;
					for(int h=0;h<s[0][k].size();h++){
						if(t[0][j+h]!=s[0][k][h]||t[1][j+h]!=s[1][k][h]){
							x=1;
							break;
						}
					}
					if(!x){
						sum++;
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}