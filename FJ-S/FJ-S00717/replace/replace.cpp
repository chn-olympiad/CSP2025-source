#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[1000010][5],t[1000010][5];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		int nw=0,ts=t[i][1].size(),ans=0;
		for(int j=1;j<=n;j++){
			while(nw<=ts){
				int ii=t[i][1].find(s[j][1],nw),ss=s[j][1].size(),flag=1;
//				cout<<ii<" ";
				nw=ii+1;
				if(ii==-1)break;
				for(int k=ii;k<=ii+ss-1;k++){
					if(s[j][2][k-ii]!=t[i][2][k]){
						flag=0;
						break;
					}
				}
				if(!flag){
					continue;
				}
				for(int k=0;k<ii;k++){
					if(t[i][1][k]!=t[i][2][k]){
						flag=0;
						break;
					}
				}
				if(!flag){
					continue;
				}
				for(int k=ii+ss;k<ts;k++){
					if(t[i][1][k]!=t[i][2][k]){
						flag=0;
						break;
					}
				}
				if(!flag){
					continue;
				}
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

