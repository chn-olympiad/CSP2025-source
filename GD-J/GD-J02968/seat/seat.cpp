#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],k,s,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
    k=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
    	if(a[i]==k){
    		s=n*m-i+1;
			break;
		}
	} 
	if(s/m<s*1.0/m)
	x=s/m+1;
	else
	x=s/m;
	if(x%2)
	{
		if(s%m==0)
		y=n;
		else
		y=s%m;
	}
	else
	{
		if(s%m==0)
		y=1;
		else
		y=n-s%m+1;
	}
	printf("%lld %lld",x,y);
	return 0;
}
