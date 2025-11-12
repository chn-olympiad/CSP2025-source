#include<bits/stdc++.h>
#define rd read()
#define el putchar('\n')
#define QAQ printf("QAQ");
using namespace std;
typedef long long ll;

ll read(){
	char ch=getchar();
	ll x=0,flag=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			flag=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*flag;
}
void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
}

const ll MAXN=5e5+5,MAXP=(1<<20)+5,inf=1e18,mod=1e9+7;
ll n,k,ans;
ll a[MAXN];
void solveA(){
	write(n/2);
}
void solveB(){
	if(k==0){
		ll ans=0;
		for(int i=1,x;i<=n;i++){
			if(a[i]==0){
				ans++;
			}else{
				x++;
				if(x==2){
					ans++;
					x=0;
				}
			}
		}
		write(ans);
	}else{
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		write(ans);
	}
}
ll suf[MAXN];
void solve(){
	ll l=1;
	for(int i=1;i<=n;i++){            
		suf[i]=suf[i-1] xor a[i];
		for(int j=i;j>=l;j--){
			ll x=suf[i] xor suf[j-1];
			if(x==k){
				ans++;
				l=i+1;
				break;
			}
		}
	}
	write(ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=rd,k=rd;
	bool A=true,B=true;
	for(int i=1;i<=n;i++){
		a[i]=rd;
		if(a[i]!=1){
			A=false;
		}
		if(a[i]!=0&&a[i]!=1){
			B=false;
		}
	}
	if(A){
		solveA();
		return 0;
	}
	if(B){
		solveB();
		return 0;
	}
	solve();
	return 0;
}
