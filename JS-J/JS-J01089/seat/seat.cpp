#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,id,x,y;
int a[1145];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=(int)n*m;i++)
	scanf("%lld",&a[i]);
	id=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==id){
			id=i;
			break;
		}
	}
	x=id/n+(id%n!=0);
	id%=n;
	if(x%2==1) y=id+n*(id==0);
	else y=n-id+1-n*(id==0);
	printf("%lld %lld",x,y);
	return 0;
}
