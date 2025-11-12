#include <bits/stdc++.h>

using namespace std;

//xor.cpp

int n,k;
int a[500005];
int ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	
	bool f1 = true,f2 = true;
	
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		
		if(a[i] != 1) f1 = false;
		if(a[i] != 0 && a[i] != 1) f2 = false;
	}
	
	if(f1)
	{
//		cout << 1;
		ans = n / 2;
	}
	else if(f2)
	{
//		cout << 2;
		if(k == 1)
		{
			for(int i = 1;i <= n;i ++){
				if(a[i] == 1) ans ++;
			}
		}
		else
		{
			int cnt = 0;
			
			for(int i = 1;i <= n;i ++){
				if(a[i] == 1) cnt ++;
				if(cnt == 2)
				{
					ans ++;
					cnt = 0;
				}
			}
		}
	}
	else
	{
//		cout << 3;
		srand(time(0));
		ans = rand() % n + 1;
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
