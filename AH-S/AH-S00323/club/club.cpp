#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10,M=1e5+10;
int a[M][3];//0,1,2

pair<int,int> a0[M],a1[M],a2[M];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(a0,0,sizeof a0);
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);

		int n,num0=0,num1=0,num2=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);

			if(a[i][0]>a[i][1] && a[i][0]>a[i][2])//0
			{
				num0++;
				a0[num0-1].second=N-a[i][0];
				a0[num0-1].first=N-a[i][0]+max(a[i][1],a[i][2]);
			}


			else if(a[i][1]>a[i][0] && a[i][1]>a[i][2])//1
			{
				num1++;
				a1[num1-1].second=N-a[i][1];
				a1[num1-1].first=N-a[i][1]+max(a[i][0],a[i][2]);
			}

			else
			{
				num2++;
				a2[num2-1].second=N-a[i][2];
				a2[num2-1].first=N-a[i][2]+max(a[i][0],a[i][1]);
			}
		}

		sort(a0,a0+num0);
		sort(a1,a1+num1);
		sort(a2,a2+num2);

		/*
		for(int i=0;i<num0;i++)
		{
			cout<<N-a0[i].second<<' '<<a0[i].first<<'\n';
		}
		cout<<endl;
		for(int i=0;i<num1;i++)
		{
			cout<<N-a1[i].second<<' '<<a1[i].first<<'\n';
		}
		cout<<endl;
		for(int i=0;i<num2;i++)
		{
			cout<<N-a2[i].second<<' '<<a2[i].first<<'\n';
		}
		cout<<endl;
		*/

		int ans=0,tmp;

		tmp=num0;
		while(num0>n/2)
		{
			ans-=N-a0[num0-1].first;
			num0--;
		}
		num0=tmp;

		tmp=num1;
		while(num1>n/2)
		{
			ans-=N-a1[num1-1].first;
			num1--;
		}
		num1=tmp;

		tmp=num2;
		while(num2>n/2)
		{
			ans-=N-a2[num2-1].first;
			num2--;
		}
		num2=tmp;

		for(int i=0;i<num0;i++) ans+=N-a0[i].second;
		for(int i=0;i<num1;i++) ans+=N-a1[i].second;
		for(int i=0;i<num2;i++) ans+=N-a2[i].second;

		cout<<ans<<endl;
	}

	return 0;
}
