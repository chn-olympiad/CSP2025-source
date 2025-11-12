#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t;
int ans[10];
struct node{
	int a,b,c;
	int maxn,best;
	int less_best;
} a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{	
		int total=0;
		vector<int> cnt_1;
		vector<int> cnt_2;
		vector<int> cnt_3;	
		//输入
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j].a);
			scanf("%d",&a[j].b);
			scanf("%d",&a[j].c);
			a[j].maxn=max(max(a[j].a,a[j].b),a[j].c);
			if(a[j].maxn==a[j].a)
			{
				a[j].best=1;
				a[j].less_best=a[j].maxn-max(a[j].b,a[j].c);	
			} 
			if(a[j].maxn==a[j].b)
			{
				a[j].best=2;
				a[j].less_best=a[j].maxn-max(a[j].a,a[j].c);	
			} 
			if(a[j].maxn==a[j].c)
			{
				a[j].best=3;
				a[j].less_best=a[j].maxn-max(a[j].a,a[j].b);	
			} 
		}	
		
		for(int j=1;j<=n;j++)
		{
			total+=a[j].maxn;
			if(a[j].best==1) cnt_1.push_back(a[j].less_best);
			if(a[j].best==2) cnt_2.push_back(a[j].less_best);
			if(a[j].best==3) cnt_3.push_back(a[j].less_best);
		} //统计 
		
		if(cnt_1.size()>n/2)
		{
			int m=cnt_1.size()-n/2;
			sort(cnt_1.begin(),cnt_1.end());
			for(int j=0;j<m;j++)
			{
				total-=cnt_1[j];
			}
		} 
		else if(cnt_2.size()>n/2)
		{
			int m=cnt_2.size()-n/2;
			sort(cnt_2.begin(),cnt_2.end());
			for(int j=0;j<m;j++)
			{
				total-=cnt_2[j];
			}
		} 
		else if(cnt_3.size()>n/2)
		{
			int m=cnt_3.size()-n/2;
			sort(cnt_3.begin(),cnt_3.end());
			for(int j=0;j<m;j++)
			{
				total-=cnt_3[j];
			}
		} 

		ans[i]=total;		
	}
	
	//输出 
	for(int i=1;i<=t;i++)
	{
		printf("%d\n",ans[i]);
	} 
	return 0;
}

