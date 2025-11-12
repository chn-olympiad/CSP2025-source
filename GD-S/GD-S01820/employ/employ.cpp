#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
int a[510],c[510];
string s;
void solve(int n,int m){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!c[i])cnt++;
	}
	if(n-cnt<m){
		printf("0");
		return;
	}
	ll fac=1;
	for(int i=1;i<=n;i++)fac=fac*i%P;
	printf("%lld",fac);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n>18){
		solve(n,m);
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]=i;
	int cnt=0;
	ll ans=0;
	do{
		cnt=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=cnt){
				cnt++;
				continue;
			}
			if(s[i]%2==0)cnt++;
		}
		if(n-cnt>=m)ans=(ans+1)%P;
	}while(next_permutation(a+1,a+n+1));
	printf("%lld",ans);
	return 0;
}
