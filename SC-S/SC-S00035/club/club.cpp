#include<bits/stdc++.h>

#define int long long

using namespace std;

int T = 0 , n = 0;

array<int , 5> tot;

struct Lilies{
	int tag;
	int val;
};

array<array<Lilies , 4> , 100100> tmp;

array<int , 100100> delta;

signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> T;
	
	while(T --)
	{
		int ans = 0;
		
		cin >> n;
		
		for(int i = 1;i <= 3;++ i) tot[i] = 0; 
		
		for(int i = 1;i <= n;++ i)
		{
			cin >> tmp[i][1].val >> tmp[i][2].val >> tmp[i][3].val;
			tmp[i][1].tag = 1;
			tmp[i][2].tag = 2;
			tmp[i][3].tag = 3;
		}
		
		for(int i = 1;i <= n;++ i)
		{
			sort(tmp[i].data() + 1 , tmp[i].data() + 3 + 1 , [&](Lilies x , Lilies y){return x.val > y.val;});
			
			ans += tmp[i][1].val;
			
			++ tot[tmp[i][1].tag];
		}
		
		if(tot[1] <= n / 2 && tot[2] <= n / 2 && tot[3] <= n / 2)
		{
			cout << ans << '\n';
			continue; 
		}
		
		int pos = 0;
		
		if(tot[1] > n / 2) pos = 1;
		else if(tot[2] > n / 2) pos = 2;
		else if(tot[3] > n / 2) pos = 3;
		
		int cnt = 0;
		
		for(int i = 1;i <= n;++ i)
		{
			if(tmp[i][1].tag == pos)
			{
				delta[++ cnt] = tmp[i][1].val - tmp[i][2].val;
			}
		}
		
		sort(delta.data() + 1 , delta.data() + cnt + 1 , [&](int x , int y){return x < y;});
		
		for(int i = 1;i <= tot[pos] - (n / 2);++ i) ans -= delta[i];
		
		cout << ans << '\n';
	}
	
	cout << endl;
	
	return 0;	
}