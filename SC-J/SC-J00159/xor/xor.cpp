#include<iostream>
#include<queue>
using namespace std;
int n,k;
const int MAXN = 500005;
int numls[MAXN];
queue<int> que;
int xor_num = 0;
void task_A()
{
	cout<<n/2;
	return ;
}
int task_10(int pos)
{
	if (pos == n)
	{
		return 1;
	}
	int max_ans = 0;
	for(int i=pos;i<=n;i++)
	{
		int xor_num = 0;
		for(int l=1;l<=n-pos+1;l++)
		{
			xor_num ^= numls[i+l-1];
			if(xor_num == k)
			{
				max_ans = max(task_10(pos+i+l), max_ans);
			}
		}
	}
	return max_ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d", &n, &k);
	int flag = true;
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &numls[i]);
		if (numls[i]!=1)
		{
			flag = false;
		}
	}
	if (k==0 && flag)
	{
		task_A();
	}
	else
	{
		cout<<task_10(1);
	}
	return 0;
}