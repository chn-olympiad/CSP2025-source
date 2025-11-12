#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
int a,b,c;
vector<int>c1,c2,c3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		c1.clear();
		c2.clear();
		c3.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c)
			{
				sum+=a;
				c1.push_back(min(a-b,a-c));
			}
			else if(b>=a&&b>=c)
			{
				sum+=b;
				c2.push_back(min(b-a,b-c));
			}
			else{
				sum+=c;
				c3.push_back(min(c-a,c-b));
			}
		}
		n/=2;
		if(c1.size()>n)	
		{
			sort(c1.begin(),c1.end());
			for(int i=0;i<(c1.size()-n);i++)
				sum-=c1[i];
		}	
		else if(c2.size()>n)	
		{
			sort(c2.begin(),c2.end());
			for(int i=0;i<(c2.size()-n);i++)
				sum-=c2[i];
		}
		else if(c3.size()>n)	
		{
			sort(c3.begin(),c3.end());
			for(int i=0;i<(c3.size()-n);i++)
				sum-=c3[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}

