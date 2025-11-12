#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[2005];
	cin>>n;
	if(n==3){
		int max=-111,sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]>max) max=a[i];
		}
		if(2*max<sum) cout<<1;
		else cout<<0;
		return 0;
	} 
	else if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==4){
		int ooo=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		int max1=-111,sum=0;
		sum=sum+a[1]+a[2]+a[3];
		max1=(max(a[1],a[2]),a[3]);
		if(2*max1<sum) ooo++;
		max1=-111,sum=0;
		sum=sum+a[1]+a[2]+a[4];
		max1=(max(a[1],a[2]),a[4]);
		if(2*max1<sum) ooo++;
		max1=-111,sum=0;
		sum=sum+a[1]+a[3]+a[4];
		max1=(max(a[1],a[3]),a[4]);
		if(2*max1<sum) ooo++;
		max1=-111,sum=0;
		sum=sum+a[2]+a[3]+a[4];
		max1=(max(a[2],a[3]),a[4]);
		if(2*max1<sum) ooo++;
		max1=-111,sum=0;
		sum=sum+a[1]+a[2]+a[3]+a[4];
		max1=max(max(a[1],a[2]),max(a[3],a[4]));
		if(2*max1<sum) ooo++;
		cout<<ooo;
		return 0;
	}
	return 0;
}
