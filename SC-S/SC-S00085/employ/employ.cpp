#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
lld n,m,sp1,ans;//方案数？？？？？？？？？？
int a[510],b[510];
bool c(int i){
	for(int j=1;j<=n;j++){
		if(b[i]==b[j]){
			return false;
		}
	}
	return true;
}
void f(){
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=i;
		sp1+=a[i];
	}
	ans=1;
	for(int i=1;i<=n;i++)ans*=i,ans%=998244353;
	printf("%lld",ans);
	return 0;
}