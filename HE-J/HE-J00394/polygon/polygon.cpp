#include<bits/stdc++.h>
using namespace std;

int a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int cnt=0;
	for(int i=0;i<n-2;i++)
	{
		int sum=a[i],maxn=a[i],cnt1=1;
		for(int j=i+1;j<n;j++)
		{
			sum += a[j];
			maxn = max(maxn,a[j]);
			if(cnt1>2)
			{
				if(sum>maxn*2)
					cnt+=3;
			}
			cnt1++;
		}
		cnt %= 998244353;
	}
	cout << cnt;
	return 0;
}

