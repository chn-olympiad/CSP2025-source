#include<bits/stdc++.h> 
using namespace std;
int n,m,x,y,z,a[200];
bool cmp(int u,int v){
	return u>v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(x==a[i]){
			y=i;
			break;
		}cout<<y<<endl;
	z=(y-1)/n+1;
	cout<<z<<" ";
	if(z%2==1)cout<<y-n*(z-1);
	else cout<<n*z-y+1;
}
