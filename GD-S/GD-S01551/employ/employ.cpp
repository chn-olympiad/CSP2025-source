#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
char s[509];
int c[509],p[509];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0,jc=1,nowdied=0,fl=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf(" %c",&s[i]);
		sum+=s[i]-48;
		jc=jc*i%mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	sort(c+1,c+n+1);
	if(sum<m){
		//pianf
		cout<<0;
		return 0;
	}
	if(n<=10){
		//n<=10 8pts
		for(int i=1;i<=n;i++)p[i]=i;
		while(1){
			fl=1;
			nowdied=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||nowdied>=c[p[i]]){
					nowdied++;
				}
			}
			if(n-nowdied>=m)ans++;
			if(next_permutation(p+1,p+n+1)!=1)break;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		ans=1;
		int die=0;
		//m==1 12pts
		for(int i=1;i<=n;i++){
			if(s[i]=='0')continue;
			ans*=lower_bound(c+1,c+n+1,i)-1-c-die;
			die++;
		}
		for(int i=die+1;i<=n;i++){
			ans*=n-i+1;
			ans%=mod;
		}
		cout<<(jc-ans+mod)%mod;
		return 0;
	}
	puts("0");
	return 0;
}
/*sum 24pts
呜呜呜，好菜，感觉应该退役了。 
*/
