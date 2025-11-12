#include<bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4
using namespace std;
long long n,m,xm;
long long a[100010];
long long zw[1010][1010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	xm=a[1];
	sort(a+1,a+1+n*m,cmp);
	long long jsq=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++) zw[i][j]=a[++jsq];
		}
		else
		{
			for(int j=m;j>=1;j--) zw[i][j]=a[++jsq];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(zw[i][j]==xm)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

