#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,k;
int a[20][20];
int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			k++;
			b[k]=a[i][j];
		}
	int xr=b[1];
	sort(b+1,b+1+k);
	for(int i=k;i>=1;i--)
		if(b[i]==xr)
		{
			int zzc=k-i+1;
			int y=1,x;
			if(zzc%m==0)
				x=zzc/m,ans=x;
			else
				x=zzc/m+1,ans=x-1;
			if(x%2==1)
				y=m-(x*m-zzc);
			else
				y=x*m-zzc+1;
			cout<<x<<" "<<y<<endl;
		}
	return 0;
}
//16:00~20:00 4h
