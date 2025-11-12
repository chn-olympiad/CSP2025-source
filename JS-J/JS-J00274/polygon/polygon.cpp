#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n;
int arr[5005],sarr[5005];
bool check(int l,int r)
{
	//cout<<arr[r]<<"  sa"<<sarr[r]<<"l "<<sarr[l - 1]<<endl;//
	if(2 * arr[r] < (sarr[r] - sarr[l - 1])) return true;
	else return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>arr[i];
	}
	sort(arr + 1,arr + n + 1);
	int ans = 0;
	sarr[1] = arr[1];//qian zhui he
	for(int i = 2;i <= n;i++)
	{
		sarr[i] = sarr[i - 1] + arr[i];
	}
	/*for(int i = 1;i <= n;i++)//
	{
		cout<<sarr[i]<<endl;//
	}//*/
	//int l = 1,r = 3;//shuang zhi zheng
	for(int i = 3;i <= n;i++)
	{
		for(int j = 1;j <= n - (i - 1);j++)
		{
			//cout<<"j"<<j<<"r"<<j + i - 1<<endl;//
			if(check(j,j + i - 1))
			{
				ans++;
				//cout<<"l"<<j<<"r"<<j + i - 1<<endl;//
			}
		}
	}
	cout<<ans;
	return 0;
}
