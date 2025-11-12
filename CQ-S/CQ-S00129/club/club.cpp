#include<bits/stdc++.h>
using namespace std;
const int NR = 1e5 + 10;
int a[NR] , b[NR] , c[NR];
struct node
{
	int x,y,idx;	
};

bool operator < (node x,node y)
{
	return  x.y > y.y;
}
//我了大模拟.. 15:26 

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a)) , memset(b,0,sizeof(b)) , memset(c,0,sizeof(c));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		int ans = 0;
		int cnta = 0 , cntb = 0 , cntc = 0;
		priority_queue<node> qa,qb,qc;
		for(int i=1;i<=n;i++)
		{
			if(a[i] >= b[i] && a[i] >= c[i])//可以选进A，而且最大
			{
				ans += a[i];
				cnta ++ ;
				qa.push({a[i],min(a[i] - b[i] , a[i] - c[i]),i});
			}
			else if(b[i] >= a[i] && b[i] >= c[i])
			{
				ans += b[i];
				cntb ++ ;
				qb.push({b[i] , min(b[i] - c[i] , b[i] - a[i]),i});
			}
			else if(c[i] >= a[i] && c[i] >= b[i])
			{
				ans += c[i];
				cntc ++ ;
				qc.push({c[i] , min(c[i] - a[i] , c[i] - b[i]),i});
			}
		}
		
		if(cnta > n / 2 && cntb <= n / 2 && cntc <= n / 2)//只有a多了 
		{
			while(cnta > n / 2)
			{
				node x = qa.top();
				qa.pop();
				cnta -- ;
				ans -= x.x;
				if(a[x.idx] - b[x.idx] == x.y)//到b减小的代价最少 
				{
					qb.push({b[x.idx] , a[x.idx] - b[x.idx] , x.idx});
					cntb++;
					ans += b[x.idx];
				}
				else //到c减小的代价最少 
				{
					qc.push({c[x.idx] , a[x.x] - c[x.x] , x.idx});
					cntc++;
					ans += c[x.idx];
				}
			}
			//cnta现在为n/2,不用讨论剩下情况 
		}
		
		else if(cntb > n / 2 && cnta <= n / 2 && cntc <= n / 2)//只有b多了 
		{
			while(cntb > n / 2)
			{
				node x = qb.top();
				qb.pop();
				cntb -- ;
				ans -= x.x;
				if(b[x.idx] - a[x.idx] == x.y)//到a减小的代价最少 
				{
					qa.push({a[x.idx] , b[x.idx] - a[x.idx] ,  x.idx});
					cnta++;
					ans += a[x.idx];
				}
				else //到c减小的代价最少 
				{
					qc.push({c[x.idx] , b[x.idx] - c[x.idx] , x.idx});
					cntc++;
					ans += c[x.idx];
				}
			}
		}
		
		else if(cntc > n / 2 && cnta <= n / 2 && cntb <= n / 2)//只有c多了 
		{
			while(cntc > n / 2)
			{
				node x = qc.top();
				qc.pop();
				cntc -- ;
				ans -= x.x;
				if(c[x.idx] - a[x.idx] == x.y)//到a减小的代价最少 
				{
					qa.push({a[x.idx] , c[x.idx] - a[x.idx] ,  x.idx});
					cnta++;
					ans += a[x.idx];
				}
				else //到b减小的代价最少 
				{
					qb.push({b[x.idx] , c[x.idx] - b[x.idx] ,  x.idx});
					cntb++;
					ans += b[x.idx];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
思路1：
先按照最大的来分，满人数后再做调整 
//100pts 
*/
