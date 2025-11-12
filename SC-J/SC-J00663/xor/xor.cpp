#include <bits/stdc++.h>
using namespace std;

int n[500005];//n数组用于存储数据
int len_;
long long k; // len_用于存贮数的数量, k存储目标结果
int ans = 0;//ans做输出结果(即区间数量)
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> len_ >> k;
	for (int i = 0; i < len_; i++)
	{
		cin >> n[i];
	}
	for (int i = 0; i < len_; i++)//i在数组内循环
	{
		long long cnt = 0; //cnt临时记录当前区间的异或和
		for(int j = i; j < len_; j++)//j表示区间查找的下标
		{
			cnt ^= n[j];
			if(cnt == k)
			{
				ans ++;
				i = j;
				break;
			}
		}
		
	}
	
	cout << ans;
	return 0;
}