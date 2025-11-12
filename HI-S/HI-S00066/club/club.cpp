#include<bits/stdc++.h>
using namespace std;
struct P{
	int a,b,c,Max;
};
bool cmp(P a,P b)
{
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,sum = 0,ai = 0,bi = 0,ci = 0,cnt = 0;
		P a[100005],b[100005];
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b == 0&&a[i].c == 0) cnt++;
		}
		if(cnt==n)
		{
			sort(a,a+n,cmp);
			for(int i = 0;i<n/2;i++)
			{
				sum+=a[i].a;
			}
			printf("%d",sum);
			return 0;
		}
		for(int i = 0;i<n;i++)
		{
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			{
				ai++;
				sum+=a[i].a;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				bi++;
				sum+=a[i].b;
			}
			else
			{
				ci++;
				sum+=a[i].c;
			}
			a[i].Max = max(a[i].a,max(a[i].b,a[i].c));
		}
		while(ai>n/2||bi>n/2||ci>n/2)
		{
			if(ai>n/2)
			{
				int i = 0;
				while(ai>n/2)
				{
					if(a[i].Max == a[i].a)
					{
						sum = sum-a[i].a;
						if(a[i].b>a[i].c)
						{
							bi++;
							sum+=a[i].b;
							a[i].Max = a[i].b;
						}
						else
						{
							ci++;
							sum+=a[i].c; 
							a[i].Max = a[i].c;
						}
						ai--;
					}
					i++;
				}
			}
			if(bi>n/2)
			{
				int i = 0;
				while(bi>n/2)
				{
					if(a[i].Max == a[i].b)
					{
						sum = sum-a[i].b;
						if(a[i].a>a[i].c)
						{
							ai++;
							sum+=a[i].a;
							a[i].Max = a[i].a;
						}
						else
						{
							ci++;
							sum+=a[i].c; 
							a[i].Max = a[i].c;
						}
						bi--;
					}
					i++;
				}
			}
			if(ci>n/2)
			{
				int i = 0;
				while(ci>n/2)
				{
					if(a[i].Max == a[i].c)
					{
						sum = sum-a[i].c;
						if(a[i].a>a[i].b)
						{
							ai++;
							sum+=a[i].a;
							a[i].Max = a[i].a;
						}
						else
						{
							bi++;
							sum+=a[i].b; 
							a[i].Max = a[i].b;
						}
						ci--;
					}
					i++;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
