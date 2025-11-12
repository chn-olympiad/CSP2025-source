#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],tmp;
pair<int,int> calc(int x){
	pair<int,int>res;
	int candybar=lower_bound(a+1,a+1+n*m,x)-a;
	res.first=(candybar-1)/m+1;res.second=res.first%2==1?(candybar-1)%m+1:m-(candybar-1)%m;
	return res;
}	
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);for(int i=1;i<=n*m;i++)scanf("%lld",&a[i]),a[i]=-a[i];tmp=a[1];
	sort(a+1,a+1+n*m);printf("%lld %lld\n",calc(tmp).first,calc(tmp).second);
	return 0;
}
