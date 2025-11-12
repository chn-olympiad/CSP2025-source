#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,x1,x2,x3;
int da,db,dc;	//d数组的下标
struct stu{
	int a1,a2,a3,cha;	//cha是最大与次大的差值
}d1[N],d2[N],d3[N];
long long ans;
bool cmp(stu x,stu y)
{
	return x.cha<y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		da=db=dc=ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x1>>x2>>x3;
			if(x1>=x2&&x1>=x3)
			{
				d1[da++]={x1,x2,x3,x1-max(x2,x3)};
				ans+=x1;
			}
			else if(x2>=x1&&x2>=x3)
			{
				d2[db++]={x1,x2,x3,x2-max(x1,x3)};
				ans+=x2;
			}
			else
			{
				d3[dc++]={x1,x2,x3,x3-max(x2,x1)};
				ans+=x3;
			}
		}
		n/=2;
		if(da>n)
		{
			sort(d1,d1+da,cmp);
			for(int i=0;i<da-n;i++)
			ans-=d1[i].cha;
		}
		else if(db>n)
		{
			sort(d2,d2+db,cmp);
			for(int i=0;i<db-n;i++)
			ans-=d2[i].cha;
		}
		else if(dc>n)
		{
			sort(d3,d3+dc,cmp);
			for(int i=0;i<dc-n;i++)
			ans-=d3[i].cha;
		}
		cout<<ans<<endl;
	}
	return 0;
}
