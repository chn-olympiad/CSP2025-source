#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x;
int a[105];
bool cmp(int a,int b) { return a>b; }
int l(int q) { return (q-1)/n+1; }
int h(int q){
	if(l(q)%2==1) return (q-1)%n+1;
	return n*l(q)+1-q;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<l(i)<<' '<<h(i);
			break;
		}
	}
	return 0;
}