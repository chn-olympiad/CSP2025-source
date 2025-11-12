#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, k, curw, res = 0;cin>>n>>k;
	vector<ll> num,wgh;
	cin >> curw;
	num.push_back(curw);
	for(ll i = 1; i < n; ++i)
	{
		ll tmp;cin>>tmp;
		num.push_back(tmp);
	}
	if(k == 0)
	{
		if(n <= 2){
			cout << (n == 2);
			return 0;
		}
		else{
			int sum=0;
			for(int i :num)
			{
				if(i==0){++res;sum=0;
				}
				else {sum^=i;
				if(sum==k)++res;sum=0;
				}
			}
		}
	}else if(k == 1){
		
	}
	else{
		for(int l = 0; l < n; ++l){
			ll sum = 0;
			for(int i = l; i < n; ++i)
			{
				sum ^= num[i];
				if(sum == k)
				{
					++res;
					sum = 0;
				}
			}
		}
	}
	cout<< res;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
