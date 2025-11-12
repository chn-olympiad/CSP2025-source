#include<bits/stdc++.h>
using namespace std;
bool markA=1;
const int P=1e5+5;
int t,n,sum;
int a[P],b[P],c[P],maxx=INT_MIN;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		
		maxx=0;
		sum=0;
		cin>>n;
		if(n==2) 
		{
			int a11,a22,a33,a44,a55,a66;
			cin>>a11>>a22>>a33>>a44>>a55>>a66;
			int a1=a11+a55;
			int a2=a11+a66;
			int a3=a22+a44;
			int a4=a22+a66;
			int a5=a33+a44;
			int a6=a33+a55;
			int max1=max(a1,a2);
			int max2=max(a3,a4);
			int max3=max(a5,a6);
			cout<<max(max(max1,max2),max3)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0) markA=0;
		}
		if(markA)
		{
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--) sum+=a[i];
			cout<<sum<<'\n';
			continue;
		}
		if(n==4)
		{
			int d[60];
			memset(d,0,sizeof(d));
			d[0]=a[1]+a[2]+b[3]+b[4];
			d[1]=a[1]+a[2]+b[3]+c[4];
			d[2]=a[1]+a[2]+c[3]+b[4];
			d[3]=a[1]+a[2]+c[3]+c[4];
			d[4]=a[1]+b[2]+c[3]+a[4];
			d[5]=a[1]+b[2]+c[3]+b[4];
			d[6]=a[1]+b[2]+c[3]+c[4];
			d[7]=a[1]+b[2]+b[3]+a[4];
			d[8]=a[1]+b[2]+b[3]+c[4];
			d[9]=a[1]+b[2]+a[3]+b[4];
			d[10]=a[1]+b[2]+a[3]+c[4];
			d[11]=a[1]+c[2]+a[3]+b[4];
			d[12]=a[1]+c[2]+a[3]+c[4];
			d[13]=a[1]+c[2]+b[3]+a[4];
			d[14]=a[1]+c[2]+b[3]+b[4];
			d[15]=a[1]+c[2]+b[3]+c[4];
			d[16]=a[1]+c[2]+c[3]+a[4];
			d[17]=a[1]+c[2]+c[3]+b[4];
			d[18]=b[1]+a[2]+a[3]+b[4];
			d[19]=b[1]+a[2]+a[3]+c[4];
			d[20]=b[1]+a[2]+b[3]+a[4];
			d[21]=b[1]+a[2]+b[3]+c[4];
			d[22]=b[1]+a[2]+c[3]+a[4];
			d[23]=b[1]+a[2]+c[3]+b[4];
			d[24]=b[1]+a[2]+c[3]+c[4];
			d[25]=b[1]+b[2]+a[3]+a[4];
			d[26]=b[1]+b[2]+a[3]+c[4];
			d[27]=b[1]+b[2]+c[3]+a[4];
			d[28]=b[1]+b[2]+c[3]+c[4];
			d[29]=b[1]+c[2]+a[3]+a[4];
			d[30]=b[1]+c[2]+a[3]+b[4];
			d[31]=b[1]+c[2]+a[3]+c[4];
			d[32]=b[1]+c[2]+b[3]+a[4];
			d[33]=b[1]+c[2]+b[3]+c[4];
			d[34]=b[1]+c[2]+c[3]+a[4];
			d[35]=b[1]+c[2]+c[3]+b[4];
			d[36]=c[1]+a[2]+a[3]+b[4];
			d[37]=c[1]+a[2]+a[3]+c[4];
			d[38]=c[1]+b[2]+a[3]+a[4];
			d[39]=c[1]+b[2]+a[3]+b[4];
			d[40]=c[1]+b[2]+a[3]+c[4];
			d[41]=c[1]+c[2]+a[3]+a[4];
			d[42]=c[1]+c[2]+a[3]+b[4];
			d[43]=c[1]+a[2]+b[3]+a[4];
			d[44]=c[1]+a[2]+b[3]+b[4];
			d[45]=c[1]+a[2]+b[3]+c[4];
			d[46]=c[1]+a[2]+c[3]+a[4];
			d[47]=c[1]+a[2]+c[3]+b[4];
			d[48]=c[1]+b[2]+b[3]+a[4];
			d[49]=c[1]+b[2]+b[3]+c[4];
			d[50]=c[1]+b[2]+c[3]+a[4];
			d[51]=c[1]+b[2]+c[3]+b[4];
			d[52]=c[1]+c[2]+b[3]+a[4];
			d[53]=c[1]+c[2]+b[3]+b[4];
			for(int i=0;i<54;i++) maxx=max(maxx,d[i]);
			cout<<maxx<<'\n';
		}
		else
		{
			int pl=0;
			for(int i=1;i<=n;i++)
			{
				pl+=max(max(a[i],b[i]),c[i]);
			}
			cout<<pl<<'\n';
		}
	}
	return 0;
}
