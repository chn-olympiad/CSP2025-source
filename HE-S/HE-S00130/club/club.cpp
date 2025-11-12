#include<bits/stdc++.h>
using namespace std;
struct man
{
	int xia;
	int man;
}c1[100005],c2[100005],c3[100005];
int cheng[100005];
bool cmp(man x,man y)
{
	return x.man>y.man;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int duo=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>c1[i].man>>c2[i].man>>c3[i].man;
		}
		if(n>4)
		{	
			sort(c1+1,c1+n+1,cmp);
			sort(c2+1,c2+n+1,cmp);
			sort(c3+1,c3+n+1,cmp);
			if(c2[1].man==0&&c3[1].man==0)
			{
				int sum=0;
				for(int j=1;j<=duo;j++)
				sum+=c1[j].man;
				cout<<sum;
			}
		}
		else
			{
				int sum;
				if(n==2)
				{
					sum=max(c1[1].man+c2[2].man,c1[1].man+c3[2].man);
					sum=max(sum,c2[1].man+c3[2].man);
					sum=max(sum,c2[1].man+c1[2].man);
					sum=max(sum,c3[1].man+c1[2].man);
					sum=max(sum,c3[1].man+c2[2].man);
				}
				if(n==3)
				{
					sum=max(c1[1].man+c2[2].man+c3[3].man,c1[1].man+c2[3].man+c3[2].man);
					sum=max(sum,c1[2].man+c2[3].man+c3[1].man);
					sum=max(sum,c1[2].man+c2[1].man+c3[3].man);
					sum=max(sum,c1[3].man+c2[2].man+c3[1].man);
					sum=max(sum,c1[3].man+c2[1].man+c3[2].man);
				}
				cout<<sum;
			}
	}
	return 0;
}
