#include<bits/stdc++.h>
using namespace std;
int n,a[15],b[5005][5005],t,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	if(n==3)
	{
		for(int i=1; i<=n; i++)cin>>a[i];
		sort(a+1,a+n+1);
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
	}
	else 
	{
		for(int i=1; i<=n; i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++)b[1][i]=a[i];
		for(int i=2; i<=n; i++)
			for(int j=2; j<=n; j++)
				b[i][j]=b[i-1][j-1]+a[j];
		for(int i=3; i<=n; i++)
			for(int j=3; j<=n; j++)
				if(b[i][j]>a[j]*2)ans++;
		cout<<ans;
	}
	return 0;
}
