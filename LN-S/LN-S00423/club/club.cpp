#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n;
int maxm;
int man[4];
int t;
struct my
{
	int m1;
	int m2;
	int m3;
	int ma;
	int mah;
	int ma2;
	int ma2h;
} a[N];
int m22(my x,my y)
{
	if(x.ma>y.ma)
	{
		if(x.mah!=y.mah)
		{
			maxm+=x.ma+y.ma;
		}
		else
		{
			maxm+=x.ma+y.ma2;
		}
	}
	else
	{
		if(y.mah!=x.mah)
		{
			maxm+=x.ma+y.ma;
		}
		else
		{
			maxm+=y.ma+x.ma2;
		}
	}
	return maxm;
}
bool cmp(my i,my j)
{
	if(i.ma==j.ma)
	{
		return i.ma2>j.ma2;
	}
	return i.ma>j.ma;
}
signed main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
	
		cin>>n;
		for(int j=1;j<4;j++)
		{
			man[j]=0;
		}
		maxm=0;
		for(int i=0;i<n;i++)
		{
			
		
			
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			if(a[i].m1>a[i].m2&&a[i].m2>a[i].m3)
			{
				a[i].ma=a[i].m1;
				a[i].mah=1;
				a[i].ma2=a[i].m2;
				a[i].ma2h=2;
			}
			if(a[i].m1>a[i].m3&&a[i].m3>a[i].m2)
			{
				a[i].ma=a[i].m1;
					a[i].mah=1;
					a[i].ma2=a[i].m3;
					a[i].ma2h=3;
			}
				//a[i].ma=a[i].m1;
				if(a[i].m3>a[i].m2&&a[i].m2>a[i].m1)
				{
					
					a[i].ma=a[i].m3;
					a[i].mah=3;
					a[i].ma2=a[i].m2;
					a[i].ma2h=2;
				}
				if(a[i].m3>a[i].m1&&a[i].m1>a[i].m2)
				{
					a[i].ma=a[i].m3;
					a[i].mah=3;
					a[i].ma2=a[i].m1;
					a[i].ma2h=1;
				}
				
			
			if(a[i].m2>a[i].m1&&a[i].m1>a[i].m3)
			{
				
					a[i].ma=a[i].m2;
					a[i].mah=2;
					a[i].ma2=a[i].m1;
					a[i].ma2h=1;
				}
				if(a[i].m2>a[i].m3&&a[i].m3>a[i].m1)
				{
					a[i].ma=a[i].m2;
					a[i].mah=2;
					a[i].ma2=a[i].m3;
					a[i].ma2h=3;
				}
		
	}
		if(n==2)
		{
			cout<<m22(a[0],a[1])<<endl;
			continue;
		}	
		sort(a,a+n,cmp);//F1排头（A）F2（现）（B）
		/*for(int i=0;i<n;i++)
		{
			//cout<<a[i].mah<<" ";
			if(man[a[i].mah]!=-1)
			{
				man[a[i].mah]++;
				maxm+=a[i].ma;
				//cout<<maxm<<endl;
			}
			else
			{
				//if(man[a[i].ma2h]!=-1)
				//{
					maxm+=a[i].ma2;
					//cout<<a[i].ma2<<" ";
					man[a[i].ma2h]++;
					//cout<<maxm<<endl;
				//}
			}
			if(man[a[i].mah]==n/2)
			{
				man[a[i].mah]=-1;
			}
			//if(man[a[i].ma2h]==n/2)
			//{
			//	man[a[i].ma2h]=-1;
			//}
		}*/
		for(int i=0;i<n/2;i++)
		{
			
			maxm+=a[i].ma;
			//man[a[i],mah]++;
			
		}
			
		cout<<maxm<<endl;
		
	}

	return 0;
}
