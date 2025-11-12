#include<bits/stdc++.h>
using namespace std;
int t,n,pj,f;
long long sum,ss,maxn,s[3];
struct stu
{
	int p[4],q[4],id[4];
	int sum;
}a[100024];
bool cmp(stu x,stu y)
{
	if(x.p[1]-x.p[2]!=y.p[1]-y.p[2])return x.p[1]-x.p[2]>y.p[1]-y.p[2];
	else if(x.p[2]-x.p[3]!=y.p[2]-y.p[3])return x.p[2]-x.p[3]>y.p[2]-y.p[3];
	return x.p[3]>y.p[3];
}
bool cmpp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		s[1]=s[2]=s[3]=sum=0;
		for(int i=1;i<=n;i++)
		{
			ss=0;
			maxn=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i].p[j];
				a[i].q[j]=a[i].p[j];
				a[i].sum+=a[i].p[j];
			}sort(a[i].p+1,a[i].p+4,cmpp);
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					if(a[i].q[k]==a[i].p[j])
					{
						a[i].id[j]=k;
						a[i].q[k]=114514;//>1e4
					}
				}
			}
		}sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(s[a[i].id[j]]<n/2)
				{
				//	cout<<"chose "<<a[i].p[j]<<" for "<<i<<" "<<s[a[i].id[j]]<<'\n';
					sum+=a[i].p[j];
					s[a[i].id[j]]++;
					break;
				}
			}
		}
		cout<<sum<<'\n';
	}
}//Ren5Jie4Di4Ling5%
