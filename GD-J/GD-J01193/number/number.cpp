#include <bits/stdc++.h>
using namespace std;
//long long
long long sum[15];

signed main()
{
	//T1正常水平
	//我很不理解为什么我第一版代码最后一个评测点总会少数字
	//现在好了
	//怎么又多了
	//输错了 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//zph的特色标记
	//ccf orz
	//noi orz
	//cspj orz
	//luogu orz
	//tuling orz
	//noip orz
	//csps orz
	//teachers orz
	//machine orz
	//all things orz
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); 
	string a;
	cin >> a;
	for(long long i = 0;i<a.size();i++)
	{
		if(a[i] == '0')
		{
			sum[0]++;
		}
		if(a[i] == '1')
		{
			sum[1]++;
		}
		if(a[i] == '2')
		{
			sum[2]++;
		}
		if(a[i] == '3')
		{
			sum[3]++;
		}
		if(a[i] == '4')
		{
			sum[4]++;
		}
		if(a[i] == '5')
		{
			sum[5]++;
		}
		if(a[i] == '6')
		{
			sum[6]++;
		}
		if(a[i] == '7')
		{
			sum[7]++;
		}
		if(a[i] == '8')
		{
			sum[8]++;
		}
		if(a[i] == '9')
		{
			sum[9]++;
		}
		//优雅的代码
	}
	for(int i = 9;i>=0;i--)
	{
		for(long long j = 1;j<=sum[i];j++)
		{
			cout << i;
		}
	}
	return 0;
}
