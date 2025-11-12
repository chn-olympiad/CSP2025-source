#include<bits/stdc++.h>

#define int long long

using namespace std;

int n = 0 , q = 0;

array<string , 200100> str1 , str2 , quest1 , quest2;

array<pair<int , int> , 2100> num1 , num2;

signed main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> q;
	
	for(int i = 1;i <= n;++ i)
	{
		cin >> str1[i] >> str2[i];
	}
	
	for(int i = 1;i <= q;++ i)
	{
		cin >> quest1[i] >> quest2[i];
	}
	
	for(int i = 1;i <= q;++ i)
	{
		int L = 0 , R = 0 , res = 0;
		
		if(quest1[i].length() != quest2[i].length())
		{
			cout << 0 << '\n';
			continue;
		}
		
		int len = quest1[i].length();
		
		for(int x = 0;x < len;++ x)
		{
			if(quest1[i][x] != quest2[i][x])
			{
				L = x;
				break;
			}
		}
		
		for(int x = len - 1;x >= 0;-- x)
		{
			if(quest1[i][x] != quest2[i][x])
			{
				R = x;
				break;
			}
		}
		
		string tmp1 = quest1[i].substr(L , R - L + 1);
		string tmp2 = quest2[i].substr(L , R - L + 1);
		
		for(int x = 1;x <= n;++ x)
		{
			int last = 0 , cnt1 = 0 , cnt2 = 0;
			
			string tmp = str1[x];
			
			while(tmp.find(tmp1) != -1)
			{
				int pos = tmp.find(tmp1);
				
				int idl = last + pos , idr = last + pos + R - L;
				
				num1[++ cnt1] = {idl , idr};
				
				tmp.erase(0 , pos + 1);
				
				last += pos + 1;
			}
			
			last = 0;
			
			int it = 1 , flag = 0;
			
			tmp = str2[x];
			
			while(tmp.find(tmp2) != -1)
			{
				int pos = tmp.find(tmp2);
				
				int idl = last + pos , idr = last + pos + R - L;
				
				while(it <= cnt1 && (idl != num1[it].first || idr != num1[it].second)) ++ it;
				
				if(it <= cnt1 && make_pair(idl , idr) == num1[it])
				{
					flag = 1;
					break;
				}
				
				tmp.erase(0 , pos + 1);
				
				last += pos + 1;
			}
			
			if(flag) ++ res;
		}
		
		cout << res << '\n';
	}
	
	cout << endl;
	
	return 0;
}