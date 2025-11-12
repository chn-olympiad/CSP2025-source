// Head 
#include <bits/stdc++.h>
using namespace std;

// using
const int MAXN=1e5+7;

struct Node
{
	int a,b,c,max6,sec,lst;
} m[MAXN];

// 尝试过暴力搜索, 没写过, 不会写
//int n,up;
//int maxn,now;
//int cnta,cntb,cntc;
//
//int cnt=0;

//void search(int k)
//{
//	if(k==n+1)
//	{
//		if(cnta<up&&cntb<up&&cntc<up)
//			maxn=max(now,maxn);
//		return;
//	}
//	cout << ++cnt<<' '<<cnta <<' '<< cntb <<' '<< cntc<<endl;
//	now+=m[k].max;
//	search(k+1);
//	now-=m[k].max;
//	now+=m[k].sec;
//	search(k+1);
//	now-=m[k].sec;
//}

// sort method
bool cmp(Node a,Node b)
{
	if(a.max6!=b.max6) return a.max6>b.max6;
	return a.sec>b.sec;
}

// Task2
bool thesame(int i,int j,int k,int l)
{
	int tong[10];
	tong[i]++;
	tong[j]++;
	tong[k]++;
	tong[l]++;
	for(int i=0; i<5; i++)
	{
		if(tong[i]>2)return false;
	}
	return true;
}

int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	//freopen
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		// Task1
		if(n==2)
		{
			cin>>m[0].a>>m[0].b>>m[0].c;
			cin>>m[1].a>>m[1].b>>m[1].c;
			cout << max(m[0].a,max(m[0].b,m[0].c))+max(m[1].a,max(m[1].b,m[1].c))<<endl;
			continue;
		}
		
		// Task2(看到4重循环真的不会想笑嘛) 
		if(n==4)
		{
			int x[10][10];
			int max1=-1;
			for(int i=0; i<4; i++)
			{
				for(int j=0; i<3; j++)
				{
					cin >> x[i][j];
				}
			}
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					for(int k=0; k<3; k++)
					{
						for(int l=0; l<3; l++)
						{
							if(thesame(i,j,k,l))
							{
								max1=max(max1,x[1][i]+x[2][j]+x[3][k]+x[4][l]);
							}
						}
					}
				}
			}
			cout << max1 << endl;
			continue;
		}
		
		// sp.A and sp.B 
		int ans=0;
		for(int i=0; i<n; i++)
		{
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].max6=max(m[i].a,max(m[i].b,m[i].c));
			m[i].lst=min(m[i].a,min(m[i].b,m[i].c));
			m[i].sec=m[i].a+m[i].b+m[i].c-m[i].max6-m[i].lst;
			cout << m[i].max6<<' '<<m[i].lst<<' '<<m[i].sec<<endl;
		}
		sort(m,m+n,cmp);
		for(int i=0; i<n/2; i++)
		{
			ans+=m[i].max6;
		}
		for(int i=n/2; i<n; i++)
		{
			ans+=m[i].sec;
		}
		cout << ans << endl;
		continue;
	}
	return 0;
}

// 17:56
// byd考这么久一题都写不出来
// 疑似报复上午J组奶龙题目
// tnnd S组出这么难
// 写不出来啊!
// 总结:
// T1骗分
// T2 T3 也不会写
// T4 骗sp.A
// 以后都不用来了
// 挺感慨的
// 最后说一句
// 我是奶龙
 
 
