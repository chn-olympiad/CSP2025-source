#include<bits/stdc++.h>
using namespace std;

struct P
{
	int id;
	int amax;
	int hv[4];
	void clear()
	{
		amax=-2;
	}
	void findmax()
	{
		amax=max(hv[1],hv[2]);
		amax=max(amax,hv[3]);
	} 
	
};
P a[100005];

bool cmp(P x,P y)
{
	return x.amax>y.amax;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int club1,club2,club3;
		club1=club2=club3=0;
		bool club1e,club2e,club3e;
		club1e=club2e=club3e=0;
		int happy_v=0;
		
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			a[i].id=i;
			cin >> a[i].hv[1] >> a[i].hv[2] >> a[i].hv[3];
			a[i].findmax();
		}
		while(club1+club2+club3<n)
		{
			sort(a+1,a+n+1,cmp);
//			for(int i=1;i<=n;i++)
//			{
//				cerr << a[i].amax << " ";
//			}
			//cerr << endl;
			//cerr << club1+club2+club3 << endl;
			for(int i=1;i<=n;i++)
			{
				if(a[i].amax==-2) continue;
				if(a[i].amax==a[i].hv[1] && club1<n/2)
				{
					club1++;
					happy_v+=a[i].hv[1];
					a[i].clear();continue;
				}
				if(a[i].amax==a[i].hv[2] && club2<n/2)
				{
					club2++;
					happy_v+=a[i].hv[2];
					a[i].clear();continue;
				}
				if(a[i].amax==a[i].hv[3] && club3<n/2)
				{
					club3++;
					happy_v+=a[i].hv[3];
					a[i].clear();continue;
				}
			}
			if(club1==n/2 && club1e==0){
				for(int i=1;i<=n;i++)
				{
					a[i].hv[1]=-1;
				}
				club1e=1;
			}
			if(club2==n/2 && club2e==0){
				for(int i=1;i<=n;i++)
				{
					a[i].hv[2]=-1;
				}
				club2e=1;
			}
			if(club3==n/2 && club3e==0){
				for(int i=1;i<=n;i++)
				{
					a[i].hv[3]=-1;
				}
				club3e=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i].amax==-2) continue;
				a[i].findmax();
			}
		}
		cout << happy_v << endl;
	}
	return 0;
} 
