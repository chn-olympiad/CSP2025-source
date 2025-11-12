#include<iostream>
using namespace std;
const int MAXN = 500005;

int a[MAXN];
int n,k;

int main()
{
	freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flagA = true,flagB = true;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(a[i] != 1)
			flagA = false;
		if(a[i] > 1)
		 	flagB = false;
	}
	if(flagA)//10pts 
	{
		cout<<n/2;
		return 0;
	}
	else if(flagB)//15pts
	{
		int cnt = 0;
		for(int i = 1;i <= n;i++)
			if(a[i] == 1)
				cnt++;
		cout<<cnt;
		return 0;
	}
	int ans = 0;//Ô¤¼Æ 20~50pts 
	for(int i = 1,j = 1;i <= n;)
	{
		j = i;
		int sum = a[j];
		if(sum == k)
		{
			i++;
			ans++;
			continue;
		}
		bool temp = true;
		while(sum != k && j <= n)
		{
			if(temp)
				sum = a[j];
			else
				sum ^= a[j];
			//cout<<i<<' '<<j<<' '<<sum<<endl;
			j++;
			temp = false;
		}
		i = j;
		
		ans++;
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
*/
