#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
namespace lyj{
	int n,m;
	long long ans=1,cnt;
	string s;
	int main(){
		scanf("%d%d",&n,&m);
		if(n==m){
			cin>>s;
			for(int i=0;i<s.length();i++){
				if(s[i]=='0'){
					printf("0");return 0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int c;scanf("%d",c);
			if(c==0)cnt++;
		}if(n-cnt<m)ans=0;
		for(int i=1;i<=n;i++){ans*=i;ans%=mod;}
		printf("%d",ans);
		return 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	lyj::main();return 0;
}

