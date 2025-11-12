#include<bits/stdc++.h>
#define int long long
//#define ll long long
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][3],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		int ans=0,sum=0;
		cin>>t1>>t2;
		int lt=t1.size();
		for(int i=0;i<lt;i++){
			if(t1[i]!=t2[i]) sum++;
		}
		for(int i=1;i<=n;i++){
			int ls=s[i][1].size();
			if(sum>ls) continue;
			int t=t1.find(s[i][1]),tt=t;
			while(tt!=-1){
				string t3=t1.substr(0,t)+s[i][2]+t1.substr(t+ls);
				if(t3==t2) ans++;
				tt=t1.substr(t+1).find(s[i][1]);
				t+=tt+1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
