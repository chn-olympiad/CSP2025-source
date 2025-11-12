#include<bits/stdc++.h>
using namespace std;
long long T,n,a[4][100001];
long long doit(long long k,long long sma,long long smb,long long smc)
{
	
	long long max1=0,sm[4]={0,sma,smb,smc};
	if(k==1)
	{
		for(int i=1;i<=3;i++)
	if(sm[i]+1<=n/2){
	max1=max(max1,a[i][1]);}
	return max1;
	}
	for(int i=1;i<=3;i++)
	if(sm[i]+1<=n/2){
		int ns[4]={0};
		ns[i]++;
	max1=max(doit(k-1,sm[1]+ns[1],sm[2]+ns[2],sm[3]+ns[3])+a[i][k],max1);}
	return max1;
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int fl=1;
		for(int i=1;i<=n;i++)
		{cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[3][i]!=0)fl=0;}
			if(fl==1){
		long long d[100001]={0},num=0;
		for(int i=1;i<=n;i++)
		{
			d[i]=a[1][i]-a[2][i];
			num+=a[1][i];
		}
		sort(d+1,d+1+n);
		for(int i=1;i<=n/2;i++)
		{
			num-=d[i];
		}
		cout<<num<<endl;
	}
	else{
		if(n==2){
			cout<<max(max(a[1][1]+a[2][2],a[1][1]+a[3][2]),max(a[2][1]+a[1][2],max(a[2][1]+a[3][2],max(a[3][1]+a[1][2],a[3][1]+a[2][2]))))<<endl;
		}
		else{
			cout<<doit(n,0,0,0)<<endl;
		}
	}
	}
}
