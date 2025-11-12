#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int t;
struct people
{
	int id;
	int la,lb,lc;
	
}p[100005];
priority_queue<int,vector<int>,greater<int>> q;
int numx,numy,numz;
int cynumx[100005];
int cynumy[100005];
int cynumz[100005];
int cycntx;
int cycnty;
int cycntz;
void init()
{
	while(!q.empty())
	{
		q.pop(); 
	}
}
int jishu(int x,int y,int z,int id)
{
	if(x>y&&x>z)
	{
		numx++;
		cynumx[++cycntx]=id;
		return x;
	}
	if(y>x&&y>z)
	{
		numy++;
		cynumy[++cycnty]=id; 
		return y;
	}
	if(z>y&&z>x)
	{
		cynumz[++cycntz]=id; 
		numz++;
		return z;
	}
	if(x==y||y==z)
	{
		numy++;
		cynumy[++cycnty]=id; 
		numy++;
		return y;
	}
	if(x==y||x==z)
	{
		numx++;
		cynumx[++cycntx]=id; 
		numx++;
		return x;
	}
	if(z==y||x==z)
	{
		numz++;
		cynumz[++cycntz]=id; 
		numz++;
		return z;
	}
	return 12;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		int sum=0;
		memset(cynumx,0,sizeof(cynumx));
		memset(cynumy,0,sizeof(cynumy));
		memset(cynumz,0,sizeof(cynumz));
		cycntx=0,cycnty=0,cycntz=0;
		numx=0,numy=0,numz=0;
		cin>>n;
		int peomax=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].la>>p[i].lb>>p[i].lc;
			p[i].id=i;
			sum+=jishu(p[i].la,p[i].lb,p[i].lc,p[i].id);
		}
		int fullx=numx-peomax;
		int fully=numy-peomax;
		int fullz=numz-peomax;
		if(fullx>0)
		{
			init();
			for(int i=1;i<=cycntx;i++)
			{
				if(p[cynumx[i]].la-p[cynumx[i]].lb<p[cynumx[i]].la-p[cynumx[i]].lc)
				{
					q.push(p[cynumx[i]].la-p[cynumx[i]].lb);
					numx--;
					numy++;
				}
				else
				{
					q.push(p[cynumx[i]].la-p[cynumx[i]].lc);
					numx--;
					numz++;
				}
			}
			int whilefullx=fullx;
			while(whilefullx--)
			{
				sum-=q.top();
				q.pop();	
			}
			fullx=numx-peomax; 
		}
		if(fully>0)
		{
			init();
			for(int i=1;i<=cycnty;i++)
			{
				if(p[cynumy[i]].lb-p[cynumy[i]].la<p[cynumy[i]].lb-p[cynumy[i]].lc)
				{
					q.push(p[cynumy[i]].lb-p[cynumy[i]].la);
					numy--;
					numx++;
				}
				else
				{
					q.push(p[cynumy[i]].lb-p[cynumy[i]].lc);
					numy--;
					numz++;
				}
			}
			int whilefully=fully;
			while(whilefully--)
			{
				sum-=q.top();
				q.pop();	
			}
			fully=numy-peomax;
		}
		if(fullz>0)
		{
			init();
			for(int i=1;i<=cycntz;i++)
			{
				if(p[cynumz[i]].lc-p[cynumz[i]].la<p[cynumz[i]].lc-p[cynumz[i]].lb)
				{
					q.push(p[cynumz[i]].lc-p[cynumz[i]].la);
					numz--;
					numx++;
				}
				else
				{
					q.push(p[cynumz[i]].lc-p[cynumz[i]].lb);
					numz--;
					numy++;
				}
			}
			int whilefullz=fullz;
			while(whilefullz--)
			{
				sum-=q.top();
				q.pop();	
			}
			fullz=numz-peomax;
		}
		cout<<sum<<'\n';
	}
	return 0;
} 
