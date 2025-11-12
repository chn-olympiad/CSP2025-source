#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a<b;
}
int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n;cin >> n;int num[n];
	for(int i = 0;i<n;i++)
	{
		cin >> num[i];
	}
	sort(num,num+n,cmp);
	for(int long_num = 3;long_num<=n;long_num++)
	{
		
	}
}
  
