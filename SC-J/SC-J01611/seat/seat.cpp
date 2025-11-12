#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;++i)
	{
		scanf("%d",&a[i]);
	}
	int c=1,r=1,R;
	R=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;--i)
	{
		if(a[i]==R)
		{
			printf("%d %d",c,r);
			break;
		 } 
		else if(r+1<=n&&c%2==1&&c<=m) r++;
		else if(r+1>n&&(c+1)%2==0&&c+1<=m)
		{
			r=n;
			c++;
		}
		else if(r-1>=1&&c%2==0&&c<=m) r--;
		else if(r-1<1&&(c+1)%2==1&&c+1<=m)
		{
			r=1;
			c++;
		}
	}
	return 0;
} 