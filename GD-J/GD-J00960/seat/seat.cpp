#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
ll n,m,arr[N],tmp,sx,k,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	k=n*m;
	for(int i=1;i<=k;i++)scanf("%lld",&arr[i]);
	tmp=arr[1];
	sort(arr+1,arr+k+1);
	sx=lower_bound(arr+1,arr+k+1,tmp)-arr;
	sx=k-sx+1;
	l=(sx+m-1)/m;
	h=(sx+m-1)%m+1;
	if(l%2==0)h=n+1-h;
	printf("%lld %lld",l,h);
	return 0;
} 
