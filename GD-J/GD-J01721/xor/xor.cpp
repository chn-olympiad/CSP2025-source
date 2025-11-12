#include<bits/stdc++.h> 
using namespace std;
int n,k,a[1919810],beg[100005],en[100005],sl,maxx,ky[100005],tp,tp2,b[100005];
int xr(int x,int y)
{
	int l1[30]={0},l2[30]={0},s1=0,s2=0,l3[30]={0},xl=0;
	while(x)
	{
		l1[s1]=x%2;
		x/=2;s1++;
	}
	while(y)
	{
		l2[s2]=y%2;
		y/=2;s2++;
	}
	for(int i=0;i<max(s1,s2);i++)
		if(l1[i]!=l2[i])l3[i]=1;
	for(int i=0;i<=max(s1,s2);i++)
		xl+=l3[i]*pow(2,i);
	return xl;
}
//int sj(int i,int j)
//{
//	int l=0;
//	for(int x=i;x<=j;x++)
//		l=xr(l,a[x]);
//	return l;
//}
//void find(int x,int ns,int ne)
//{
//	for(int i=ne+1;i<=n;i++)
//		for(int j=i;j<=n;j++)
//		{
//			int bw=0;
//			if(i==j)bw=a[i];
//			else bw=sj(i,j);
//			if(bw==x)
//			{
//				sum++;
//				cout<<ns<<" "<<ne<<" "<<i<<" "<<j<<"\n";
//			}
//   	} 
//}       
//&&!((ns<=i&&i<=ne)||(ns<=j&&j<=ne))
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];b[i]=a[i];
		if(a[i]==1)tp++;
		if(a[i]==0)tp2++;
		a[i]=xr(a[i],a[i-1]);
	}
	if(k==0&&tp==n)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int bw=0;
			if(i==j)bw=b[i];
//			else bw=sj(i,j);
			else bw=xr(a[j],a[i-1]);
			if(bw==k)
			{
				sl++;
				beg[sl]=i,en[sl]=j;
			}
//			int s=xr(bw,k);
//			find(s,i,j);
		}	
	}
	ky[1]=1;maxx=1;
	for(int i=2;i<=sl;i++)
	{
		for(int j=i-1;j>=0;j--)
			if(en[j]<beg[i])ky[i]=max(ky[i],ky[j]+1);
		maxx=max(maxx,ky[i]);
	}
	cout<<maxx;
	return 0;
}
