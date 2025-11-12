#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct st{
	int x,s;
	bool f=0;
};
bool cmp(st a,st b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >>T;
	while(T--)
	{
		cin >>n;
		int pos[4]={},ans[4]={};
		int a,b,c;
		st maxn[n+1];
		for(int i=1;i<=n;i++)
		{
			cin >>a >>b >>c;
			maxn[i].x=max(a,max(b,c));
			if(a>b && a>c)
			{
				maxn[i].x=a;	
				maxn[i].s=1;		
			}
			else if(b>a && b>c)
			{
				maxn[i].x=b;	
				maxn[i].s=2;		
			}
			else
			{
				maxn[i].x=c;	
				maxn[i].s=3;		
			}
		}
		sort(maxn+1,maxn+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(ans[maxn[i].s]<n/2)
			{
				pos[maxn[i].s]+=maxn[i].x;
				ans[maxn[i].s]++;	
			}
		}
		cout <<pos[1]+pos[2]+pos[3] <<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
