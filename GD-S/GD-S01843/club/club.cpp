#include<bits/stdc++.h>
using namespace std;
long long t,n,g;
struct node
{
	long long a1,a2,a3;
}a[110000];
struct ham
{
	long long num,age;
}nor1[110000];
inline bool cmp(ham ax,ham ay)
{
	return min(ax.num-a[ax.age].a2,ax.num-a[ax.age].a3)<min(ay.num-a[ay.age].a2,ay.num-a[ay.age].a3);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long havi[4];
		havi[1]=0;
		havi[2]=0;
		havi[3]=0;
		g=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			nor1[++havi[1]].num=a[i].a1;
			nor1[havi[1]].age=i;
			g+=a[i].a1;
		}
		sort(nor1+1,nor1+1+n,cmp);
		bool re2=true,re3=true;
		for(int i=1;i<=n/2||(i<=n&&min(nor1[i].num-a[nor1[i].age].a2,nor1[i].num-a[nor1[i].age].a3)<0);i++)
		{
			if(re2&&re3)
			{
				g-=min(nor1[i].num-a[nor1[i].age].a2,nor1[i].num-a[nor1[i].age].a3);
			}
			else if(re2)
			{
				g-=nor1[i].num-a[nor1[i].age].a2;
			}
			else if(re3)
			{
				g-=nor1[i].num-a[nor1[i].age].a3;
			}
			if(nor1[i].num-a[nor1[i].age].a2<nor1[i].num-a[nor1[i].age].a3&&re2)
			{
				havi[2]++;
				if(havi[2]==n/2)
				{
					re2=false;
				}
			}
			else if(nor1[i].num-a[nor1[i].age].a2==nor1[i].num-a[nor1[i].age].a3)
			{
				if(havi[2]<havi[3]&&re2)
				{
					havi[2]++;
					if(havi[2]==n/2)
					{
						re2=false;
					}
				}
				else if(re3)
				{
					havi[3]++;
					if(havi[3]==n/2)
					{
						re3=false;
					}
				}
			}
			else if(re3)
			{
				havi[3]++;
				if(havi[3]==n/2)
				{
					re3=false;
				}
			}
			else if(re2)
			{
				havi[2]++;
				if(havi[2]==n/2)
				{
					re2=false;
				}
			}
		}
		cout<<g<<endl;
	}
}
