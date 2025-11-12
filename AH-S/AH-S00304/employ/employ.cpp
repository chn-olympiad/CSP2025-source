#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,p[505];
string s;
int c[505];
bool flag=true;
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		p[i]=i;
		flag=flag&&(c[i]==1);
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++){
			long long tmp=i;
			ans=ans*tmp%mod;
		}
		printf("%lld",ans);
	}
	do{
		int cnt=0,a=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||cnt>=c[p[i]]){
				cnt++;
			}
			else{
				a++;
				if(a>=m)break;
			}
		}
		if(a>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%lld",ans);
	return 0;
}
