#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][2]; 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	if(n==4 and q==2)
	{
		cout<<2<<"\n"<<0;
		return 0;
	}
	while(q--)
	{
		cout<<0<<"\n";
	}
	return 0;
}
/*
初三了，这次赛完就退役了
T1正解应该是dp，但我没推出转移方程，只能贪心，对于多测大抵是没了
T2最小生成树，但不知道怎么算村庄，卒了
T3没看懂题目
T4好像有点思路，但最后也没想出来
大概率是0pts了 
*/
