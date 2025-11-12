#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[105],r,g=1;
bool cmp(ll x,ll y){
	return(x>y);
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++) cin>>a[i];
r=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++) 
	if(a[i]==r) 
	{
		r=i;
		break;
	}
while(r>m)
{
	r-=m;
	g++;
}
if(g%2==1)
cout<<g<<" "<<r;
else cout<<g<<" "<<m-r+1;
return 0;
}
