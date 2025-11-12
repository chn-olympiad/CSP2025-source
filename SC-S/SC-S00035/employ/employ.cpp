#include<bits/stdc++.h>

#define int long long

using namespace std;

int n = 0 , m = 0 , ans = 0;

array<char , 600> str;

array<int , 600> num , per;

signed main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	cin >> (str.data() + 1);
	
	for(int i = 1;i <= n;++ i) cin >> num[i];
	
	for(int i = 1;i <= n;++ i) per[i] = i;
	
	do{
		int it = 0 , cnt = 0;
		
		for(int i = 1;i <= n;++ i)
		{
			if(it >= num[per[i]])
			{
				++ it;
				continue;
			}
			else
			{
				if(str[i] == '1') ++ cnt;
				else ++ it;
			}
		}
		
		ans += (cnt >= m); 
	}while(next_permutation(per.data() + 1 , per.data() + n + 1));
	
	cout << ans << endl;
	
	return 0;
}