#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

int t;
int a[MAXN][4];
int A[MAXN];
struct B{
	int val, pos;
}B1[MAXN], B2[MAXN];

bool cmpa(int a, int b){
	return a > b;
}

bool cmpb(B a, B b){
	return a.val > b.val;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		int n;
		bool checkA = true, checkB = true;
		long long ans = 0;
		scanf("%d", &n);
		memset(A, 0, sizeof(A));
		memset(B1, 0, sizeof(B1));
		memset(B2, 0, sizeof(B2));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				scanf("%d", &a[i][j]);
			}
			if(a[i][2] != 0 || a[i][3] != 0) checkA = false;
			if(a[i][3] != 0) checkB = false;
		}
		if(checkA)
		{
			for(int i = 1; i <= n; i++) A[i] = a[i][1];
			sort(A + 1, A + n + 1, cmpa);
			for(int i = 1; i <= (n >> 1); i++) ans += A[i];
			printf("%lld\n", ans);
			continue;
		}
		else if(checkB)
		{
			for(int i = 1; i <= n; i++)
			{
				B1[i].val = a[i][1];
				B1[i].pos = i;
				B2[i].val = a[i][2];
				B2[i].pos = i;
			}
			sort(B1 + 1, B1 + n + 1, cmpb);
			sort(B2 + 1, B2 + n + 1, cmpb);
			long long ans1 = 0, ans2 = 0;
			for(int i = 1; i <= n; i++)
			{
				if(i <= (n >> 1)){ ans1 += B1[i].val; ans2 += B2[i].val;}
				else{ ans1 += a[B1[i].pos][2]; ans2 += a[B2[i].pos][1];} 
			}
			if(ans1 >= ans2) ans = ans1;
			else ans = ans2;
			printf("%lld\n", ans);
			continue;
		}
		else
		{
			int maxx = 0;
			B s[4];
			int cnt[4];
			int m[MAXN][4], p[MAXN][4];
			memset(s, 0, sizeof(s));
			memset(cnt, 0, sizeof(cnt));
			memset(m, 0, sizeof(m));
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= 3; j++)
				{
					s[j].val = a[i][j];
					s[j].pos = j;
					sort(s + 1, s + 4, cmpb);
					m[i][1] = s[1].val; m[i][2] = s[2].val; m[i][3] = s[3].val;
					p[i][j] = s[j].pos;
				}
			}
			for(int k = 1; k <= 3; k++)
			{
				for(int i = 1; i <= n; i++)
				{
					for(int j = 1; j <= 3; j++)
					{
						if(i == 1) j = k;
						if(cnt[p[i][j]] < (n >> 1))
						{
							maxx += m[i][k];
							cnt[p[i][k]]++;
							//cout << maxx << " ";
							break;
						}
						else continue;
					}
				}
				if(maxx > ans) ans = maxx;
				memset(cnt, 0, sizeof(cnt));
				maxx = 0;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
