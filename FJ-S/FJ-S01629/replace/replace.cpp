#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+25;
ll n,q,ans;
string x,y,s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		int len=x.size();
		for(int i=1;i<=n;i++){
			int len0=s[i][0].size();
			for(int j=0;j+len0-1<len;j++){
				bool b=1;
				for(int k=j;k<=j+len0-1;k++){
					if(x[k]!=s[i][0][k-j]){
						b=0;
						break;
					}
				}
				if(b){
					string cnt=x;
					for(int k=j;k<=j+len0-1;k++){
						cnt[k]=s[i][1][k-j];
					}
					if(cnt==y){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}