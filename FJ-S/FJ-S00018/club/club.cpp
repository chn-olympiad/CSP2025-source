#include<bits/stdc++.h>
using namespace std;
struct cy{
	int a,b,c;
	int ma1,ma2,ma3;
};
struct st{
	int xb,zh;
};
bool cmp(cy x,cy y)
{
	if(x.a-x.b==y.a-y.b)
	return x.a>y.a;
	return x.a-x.b>y.a-y.b;
}
bool cmp2(st a,st b)
{
	return a.zh>b.zh;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0;
		cin>>n;
		cy k[100005];
		for(int i=0;i<n;i++)
		{
			st a[3];
			for(int i=0;i<3;i++)
			{
				cin>>a[i].zh;
				a[i].xb=i;
			}
			sort(a,a+3,cmp2);
			k[i].a=a[0].zh;
			k[i].ma1=a[0].xb;
			k[i].b=a[1].zh;
			k[i].ma2=a[1].xb;
			k[i].c=a[2].zh;
			k[i].ma3=a[2].xb;
		}
		sort(k,k+n,cmp);
		int a[3];
		for(int i=0;i<n;i++)
		{
			if(a[k[i].ma1]<=n/2)
			{
				a[k[i].ma1]++;
				sum+=k[i].a;
			}
			else if(a[k[i].ma2]<=n/2)
			{
				a[k[i].ma2]++;
				sum+=k[i].b;
			}
			else
			{
				a[k[i].ma3]++;
				sum+=k[i].c;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
