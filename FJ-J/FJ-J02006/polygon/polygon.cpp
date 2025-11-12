#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[5005];
void find(int x,int y,int z,int q)
{
	if(q==p){
		if(y>z*2) m=(m+1)%998244353;
		return;
	}
	for(int i=x+1;i<=n;i++) find(i,y+a[i],max(a[i],z),q+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		p=i;
		find(0,0,0,0);
	}
	cout<<m<<endl;
	return 0;
}