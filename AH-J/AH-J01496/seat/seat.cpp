#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,n,m,c=0,x=0,y=0,p;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){cin>>a[i];}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++)
	{
		if(i%2==1) for(j=1;j<=n;j++){c++;if(a[c]==p){x=i,y=j;break;}}
		else for(j=n;j>=1;j--){c++;if(a[c]==p){x=i,y=j;break;}} 
		if(x!=0) break;
	}
	cout<<x<<" "<<y;
}
