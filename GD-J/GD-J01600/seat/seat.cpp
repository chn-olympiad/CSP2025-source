#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll N=1e2+10;
ll n,m;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n),read(m);
//	cin>>n>>m;
	for(int i=1;i<=n*m;i++) read(a[i]);
	ll pt=a[1],rk=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==pt){
			rk=i;
			break;
		}
	}
//	cout<<rk<<"\n";
	ll c=(rk-1)/n+1,t=rk%n,r=0;
	if(c&1) r=(t-n)%n+n;
	else r=n-((t-n)%n+n)+1;
	write(c),putchar(' '),write(r);
	return 0;
}

