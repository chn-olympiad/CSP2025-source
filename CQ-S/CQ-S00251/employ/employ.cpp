#include<bits/stdc++.h>
#define ll long long
#define MAXN 505
#define mod 998244353
using namespace std;
ll ans,n,m,c[MAXN];
bool exist[MAXN],flag;
char diff[MAXN];
//stack<ll>S,A;
void choice(ll day,ll fail_num){
	if(day==n+1){
		ans=(ans+(n-fail_num>=m))%mod;
//		A=S;
////		if(n-fail_num>=m){
//			while(!A.empty()){
//				printf("%lld ",A.top());
//				A.pop();
//			}
//			putchar(' ');
//			printf("%lld %lld %lld ",fail_num,n-fail_num,m);
//			putchar('\n');
////		}
		return;
	}
	for(ll i=1;i<=n;++i){
		if(exist[i]){
			exist[i]=false;
//			S.push(i);
			choice(day+1,fail_num+((diff[day]=='0')||(fail_num>=c[i])));
//			S.pop();
			exist[i]=true;
		}
		
	}
}
ll getJC(ll n){
	if(n==1)return 1;
	return getJC(n-1)*n%mod;
}
void solByDP(){
//	f[i]=f[i-1]
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,diff+1);
//	choice(1,);
	
	ll k=0;
	for(ll i=1;i<=n;++i){
		exist[i]=true;
		scanf("%lld",&c[i]);
//		if(diff[i]=='0')flag=false;
		if(c[i]!=0)++k;
	}
	if(n==m){
		for(ll i=1;i<=n;++i){
			if(diff[i]=='0')--k;
		}
		ans=(k==n)?getJC(n):0;
	}
	else if(n<=18)choice(1,0);
	else solByDP();
	printf("%lld",ans);
//	if(m==1){
//		
//	}
//	
//	
//	if(flag){
//		for(ll i=1;i<=q;++i){
//			scanf("%lld",&c[i]);
//			if(c[i]!=0){
//				++k;
//			}
//		}
//		if(m>k){printf("0\n");return 0;}
//		
//	}
	
	return 0;
}
