#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500100];
bool u[500100];
int ans = 0;
int i, j;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	i = 1,j = 1;
	bool flag1 = 1, flag2;
	for(i = 1;i+j-1 <= n;i++)//子段长度i 
	{
		if(!flag1) break;
		int p = 0;
		for(;j <= n;j++){//子段起始位置j 
		
			int c = 0, l = 0;//c为最长没用过的区间 
			for(int k = 1;k <= n;k++){//计算最长没用过的区间 
				if(u[k]==0) l++;
				if(l > c) c = l;
			}
			if(i > c){//如果超出最大空余区间长度退出 
				flag1 = false;
				break;
			}
			flag2 = 1;
			int f = 0;
			for(int k = 1;k <= i;k++)
			{
				if(u[j+k-1]==true)//重叠了 
				{
					flag2 = 0;
					break;
				}
				f = (f^a[j+k-1]);
			}
			if(f==k&&flag2)
			{
				for(int k = 1;k <= i;k++)//标记为使用过 
					u[j+k-1] = 1;
				p++;
			}
		}
		j = 1;
		ans+=p;
	}
	cout << ans;
	return 0;
}

