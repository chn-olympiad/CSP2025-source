#include <bits/stdc++.h>
using namespace std;
struct node
{
	int d=0,id=0,club=0;
	void cl()
	{
		d=0;
		id=0;
		club=0;
	}
}maxn[100005],midn[100005],minn[100005],a[100005][5];
int cmax[5],cmid[5],cmin[5];
int sva[5][100005];
bool cmp(node x,node y)
{
	return x.d>y.d;
}
bool cmp2(node x,node y)
{
	return x.d<y.d;
}
bool sv(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		bool fa=1,fb=1;
		fa=0;
		int n;
		cin >> n;
		for(int i=1;i<=100001;i++)
		{
			maxn[i].cl();
			midn[i].cl();
			minn[i].cl();
		}
		for(int i=0;i<=4;i++)
		{
			cmax[i]=0;
			cmid[i]=0;
			cmin[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			
			for(int j=1;j<=3;j++)
			{
				cin >> a[i][j].d;
				a[i][j].id=i;
				a[i][j].club=j;
				sva[j][i]=a[i][j].d;
				if(a[i][2].d!=0)fa=0;
				if(a[i][3].d!=0)
				{
					fa=0;
					fb=0;
				}
			}
			sort(a[i]+1,a[i]+3+1,cmp);
			cmax[a[i][1].club]++;
			cmid[a[i][2].club]++;
			cmin[a[i][3].club]++;
			maxn[i].d=a[i][1].d;
			midn[i].d=a[i][1].d-a[i][2].d;
			minn[i].d=a[i][2].d-a[i][3].d;
			maxn[i].id=a[i][1].id;
			midn[i].id=a[i][2].id;
			minn[i].id=a[i][3].id;
			maxn[i].club=a[i][1].club;
			midn[i].club=a[i][2].club;
			minn[i].club=a[i][3].club;
			//cout << maxn[i].club<< ">>";
		}
		if(fa==1)
		{
			long long sum=0;
			sort(sva[1]+1,sva[1]+n+1);
			for(int i=1;i<=n/2;i++)
			{
				sum+=sva[1][i];
			}
			cout << sum << endl;
			continue;
		}
		int fmx=0,fmd=0;
		sort(maxn+1,maxn+n+1,cmp);
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=maxn[i].d;
			//cout << maxn[i].d << "''";
		}
		for(int i=1;i<=3;i++)
		{
			if(cmax[i]>n/2)
			{
				fmx=i;
			}
		}
		if(fmx==0)
		{
			cout << sum << endl;
		}
		else 
		{
			//cout << sum << "--";
			int need=cmax[fmx]-n/2;
			//cout << need << "::";
			//cout << fmx << "]]";
			sort(midn+1,midn+n+1,cmp2);
			for(int i=1;i<=n;i++)
			{
				//cout << maxn[i].club << "==";
				if(a[midn[i].id][midn[i].club].club==fmx)
				{
					sum-=midn[i].d;
					//cout << midn[i].id << "__";
					//cout << sum << "[[";
					//cout << maxn[midn[i].id].club << "..";
					need--;
				}
				if(need==0)
				{
					cout << sum << endl;
					break;
				}
			}
		}
	}
	return 0;
}
