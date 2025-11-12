#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x;
}

const int MAXN = 1e5 + 5;

int n;

long long a1 , a2 , a3;

struct Node{
	long long a1 , a2 , a3;
}p[MAXN] , pp[MAXN] , ppp[MAXN];

int cnt1 , cnt2 , cnt3;

bool cmp1(Node a , Node b)
{
	return a.a1 > b.a1;
}

bool cmp2(Node a , Node b)
{
	return a.a2 > b.a2;
}

bool cmp3(Node a , Node b)
{
	return a.a3 > b.a3;
}

int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	int T;T = read();
	while(T--)
	{
		n = read();
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		long long sum = 0;
		for(int i = 1;i <= n;i++)
		{
			a1 = read();
			a2 = read();
			a3 = read();
//			a1 -= a3;
//			a2 -= a3;
//			sum += a3;
//			a3 = 0;
			if(a1 >= a2 && a1 >= a3)
			{
				p[++cnt1].a1 = a1;
				p[cnt1].a2 = a2;
				p[cnt1].a3 = a3;
			}
			else if(a2 > a1 && a2 >= a3)
			{
				pp[++cnt2].a1 = a1;
				pp[cnt2].a2 = a2;
				pp[cnt2].a3 = a3;
			}
			else
			{
				ppp[++cnt3].a1 = a1;
				ppp[cnt3].a2 = a2;
				ppp[cnt3].a3 = a3;
			}
		}
		
		sort(p + 1 , p + 1 + cnt1 , cmp1);
		sort(pp + 1 , pp + 1 + cnt2 , cmp2);
		sort(ppp + 1 , ppp + 1 + cnt3 , cmp3);
		
//		cout << "1:\n";
//		for(int i = 1;i <= cnt1;i++)cout << p[i].a1 << " " << p[i].a2 << " " << p[i].a3 << endl;
//		cout << "2:\n";
//		for(int i = 1;i <= cnt2;i++)cout << pp[i].a1 << " " << pp[i].a2 << " " << pp[i].a3 << endl;
//		cout << "3:\n";
//		for(int i = 1;i <= cnt3;i++)cout << ppp[i].a1 << " " << ppp[i].a2 << " " << ppp[i].a3 << endl;
		
		if(cnt1 > n / 2)
		{
			for(int i = 1;i <= cnt1;i++)
			{
				long long A1 = p[i].a1 , A2 = p[i].a2 , A3 = p[i].a3;
				sum += max(A2 , A3);
				p[i].a1 = A1 - max(A2 , A3);
				p[i].a2 = A2 - max(A2 , A3);
				p[i].a3 = A3 - max(A2 , A3);
			}
			
			sort(p + 1 , p + 1 + cnt1 , cmp1);
			
//			cout << "1:\n";
//			for(int i = 1;i <= cnt1;i++)cout << p[i].a1 << " " << p[i].a2 << " " << p[i].a3 << endl;
			
			for(int i = n / 2 + 1;i <= cnt1;i++)
			{
				if(p[i].a2 >= p[i].a3)pp[++cnt2].a2 = p[i].a2;
				else ppp[++cnt3].a3 = p[i].a3;
			}
		}
		else if(cnt2 > n / 2)
		{
			for(int i = 1;i <= cnt2;i++)
			{
				long long A1 = pp[i].a1 , A2 = pp[i].a2 , A3 = pp[i].a3;
				sum += max(A1 , A3);
				pp[i].a1 = A1 - max(A1 , A3);
				pp[i].a2 = A2 - max(A1 , A3);
				pp[i].a3 = A3 - max(A1 , A3);
			}
			
			sort(pp + 1 , pp + 1 + cnt2 , cmp2);
			
//			cout << "2:\n";
//			for(int i = 1;i <= cnt2;i++)cout << pp[i].a1 << " " << pp[i].a2 << " " << pp[i].a3 << endl;
			
			for(int i = n / 2 + 1;i <= cnt2;i++)
			{
				if(pp[i].a1 >= pp[i].a3)p[++cnt1].a1 = pp[i].a1;
				else ppp[++cnt3].a3 = pp[i].a3;
			}
		}
		else if(cnt3 > n / 2)
		{
			for(int i = 1;i <= cnt3;i++)
			{
				long long A1 = ppp[i].a1 , A2 = ppp[i].a2 , A3 = ppp[i].a3;
				sum += max(A1 , A2);
				ppp[i].a1 = A1 - max(A1 , A2);
				ppp[i].a2 = A2 - max(A1 , A2);
				ppp[i].a3 = A3 - max(A1 , A2);
			}
			
//			cout << "3:\n";
//			for(int i = 1;i <= cnt3;i++)cout << ppp[i].a1 << " " << ppp[i].a2 << " " << ppp[i].a3 << endl;
			
			sort(ppp + 1 , ppp + 1 + cnt3 , cmp3);
			
			for(int i = n / 2 + 1;i <= cnt3;i++)
			{
				if(ppp[i].a1 >= ppp[i].a2)p[++cnt1].a1 = ppp[i].a1;
				else pp[++cnt2].a2 = ppp[i].a2;
			}
		}
		
		long long ans = 0;
		
		for(int i = 1;i <= min(n / 2 , cnt1);i++)ans += p[i].a1;
		for(int i = 1;i <= min(n / 2 , cnt2);i++)ans += pp[i].a2;
		for(int i = 1;i <= min(n / 2 , cnt3);i++)ans += ppp[i].a3;
		
//		cout << ans << " " << sum << endl; 
		printf("%lld\n" , ans + sum);
	}
	
	return 0;	
} 

/*

in:

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

out:

18 
4
13

*/ 