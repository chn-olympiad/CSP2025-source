#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[1005],w;
signed main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	w=a[1];
	sort(a+1,a+n*m+1),reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(w==a[i]){
			w=i;
			break;
		}
	int x=((w%n==0)?(w/n):((w/n)+1)),y=((x&1)?((w%n==0)?(n):(w%n)):(n-((w%n==0)?(n):(w%n))+1));
	return printf("%lld %lld\n",x,y),0;
}
