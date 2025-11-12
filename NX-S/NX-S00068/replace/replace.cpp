#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	string s[2][n],t[2][q];
	long long ans[q];
	for(int i=0;i<n;i++){
		cin>>s[0][i]>>s[1][i];
	}
	for(int i=0;i<q;i++){
		ans[i]=0;
		cin>>t[0][i]>>t[1][i];
		int si=t[0][i].size();
		for(int k=0;k<n;k++){
			if(si!=int(s[0][k].size())){
				break;
			}
			bool flag=1;
			for(int j=0;j<si && flag;j++){
				if(s[0][k][j]!=t[0][i][j] && s[1][k][j]!=t[1][i][j]){
					flag=0;
				} 
			}
			if(flag){
				ans[i]++;
				string x,y,z;
				int pos1,pos2;
				for(int j=0;j<si;j++){
					if(s[0][k][j]!=s[1][k][j]){
						pos1=j;
						break;
					} 
				}
				for(int j=si-1;j>=0;j--){
					if(s[0][k][j]!=s[1][k][j]){
						pos2=j;
						break;
					} 
				}
				if(pos1!=0 || pos2!=si-1){
					ans[i]++;
				}
			}
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}
