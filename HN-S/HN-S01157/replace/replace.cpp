#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
string s1[N],s2[N],s[N],x[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>x[i];
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		cin>>s1[i]>>s2[i];
		for(int j=1;j<=n;j++){
			for(int k=0;k<s1[i].size()-s[j].size()+1;k++){
				int f=0;
				string ss=s1[i];
				for(int p=0;p<s[j].size();p++){
					if(s1[i][k+p]!=s[j][p]||s2[i][k+p]!=x[j][p]){
						f=1;
						break;
					}
					ss[k+p]=x[j][p];
				}
				if(!f&&ss==s2[i]){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
