#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=120;
int n,m,r,a[N];
bool cmp(int a,int b){
	return a>b;
}
int x,y,ans;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		scanf("%lld",&a[i]);
	}
	r=a[1];
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==r){
			ans=i;
			break;
		}
	}
	if(ans%n==0) x=ans/n;
	else x=ans/n+1;
	y=ans-n*(x-1);
	if(x%2==0) y=(n-y+1);
	printf("%lld %lld",x,y);
	return 0;
}
