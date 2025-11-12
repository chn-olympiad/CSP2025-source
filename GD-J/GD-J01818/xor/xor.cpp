#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100005],f[10005][10005],n,k,bj,ans,t; 
struct stu
{int s,e;
}l[100005];
bool cmp(stu x,stu y)
{
	if(x.s==y.s)return x.e<y.e;
	return x.s<y.s;
 } 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{scanf("%d",&a[i]);if(a[i]>1)bj=1;}
	if(bj==0)
	{
		int p0=0,p1=0;
		for(int i=1;i<=n;i++)
		if(a[i]==0)p0++;else p1++;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{if(a[i]==1&&a[i+1]==1)p0++,i++;}		
			cout<<p0;	
		}
		else 
			cout<<p1;
		return 0;
	}
	for(int len=1;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1; 
			f[l][l]=a[l],f[r][r]=a[r];
			for(int k=l;k<=r;k++)
				f[l][r]=f[l][k]^f[k+1][r]; 
		}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			{if(f[i][j]==k)l[++t].s=i,l[t].e=j;}
	sort(l+1,l+t+1,cmp);
	int e=0;
	for(int i=1;i<=t;i++)
	{
		//cout<<l[i].s<<" "<<l[i].e<<endl;
		if(e<l[i].s)ans++,e=l[i].e;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
