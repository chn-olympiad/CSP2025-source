#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long

ll n, num;
ll w1, w2, w3;
ll a[100005][15];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		num = 0;
		w1 = 0, w2 = 0, w3 = 0;
		for(ll i = 1; i <= n; i++)
		{
			ll mx, mn;
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a[i][4] = -1, a[i][5] = -1, a[i][6] = -1;
			a[i][4] = max(a[i][1], max(a[i][2], a[i][3]));
			//cout << a[i][4] << " " << a[i][5] << " " << a[i][6] << " cs\n";
			if(a[i][4] == a[i][1]) w1++, mx = 1;
			else if(a[i][4] == a[i][2]) w2++, mx = 2;
			else if(a[i][4] == a[i][3]) w3++, mx = 3;
			a[i][6] = min(a[i][1], min(a[i][2], a[i][3]));
			if(a[i][6] == a[i][1]) mn = 1;
			else if(a[i][6] == a[i][2]) mn = 2;
			else if(a[i][6] == a[i][3]) mn = 3;
			//cout << a[i][4] << " " << a[i][5] << " " << a[i][6] << " cs\n";
			if((mx == 2 && mn == 3) || (mx == 3 && mn == 2)) a[i][5] = a[i][1];
			else if((mx == 1 && mn == 3) || (mx == 3 && mn == 1)) a[i][5] = a[i][2];
			else if((mx == 2 && mn == 1) || (mx == 1 && mn == 2)) a[i][5] = a[i][3];
			//cout << a[i][4] << " " << a[i][5] << " " << a[i][6] << " cs\n";
			num += a[i][4]; 
			//cout << mx << " " << mn << " mxmn\n";
		}
		//cout << "num " <<num; 
		ll minn = 0x3f3f3f, minnum;
		bool flag = 0; 
		while(w1 > n / 2)
		{ 
			flag = 1; 
			for(ll i = 1; i <= n; i++)
			{ 
				if(a[i][4] == a[i][1])
				{
					if(minn >= a[i][4] - a[i][5])
					{
						minn = a[i][4] - a[i][5];
						minnum = i; 
					}
				}
			}
			w1--;
			num -= a[minnum][4]; 
			ll zscc = a[minnum][4]; 
			a[minnum][4] = a[minnum][5];
			a[minnum][5] = zscc;
			if(a[minnum][4] == a[minnum][1]) w1++;
			if(a[minnum][4] == a[minnum][2]) w2++;
			if(a[minnum][4] == a[minnum][3]) w3++;
			num += a[minnum][4]; 
		}//cout << "num " <<num; 
		while(w2 > n / 2)
		{ 
			if(flag) 
			{
				for(ll i = 1; i <= n; i++)
				{ 
					if(a[i][4] == a[i][2])
					{
						if(minn >= a[i][4] - a[i][6])
						{
							minn = a[i][4] - a[i][6];
							minnum = i; 
						}
					}
				}
				w2--;
				num -= a[minnum][4]; 
				ll zscc = a[minnum][4]; 
				a[minnum][4] = a[minnum][6];
				a[minnum][6] = zscc;
				if(a[minnum][4] == a[minnum][1]) w1++;
				if(a[minnum][4] == a[minnum][2]) w2++;
				if(a[minnum][4] == a[minnum][3]) w3++;
				num += a[minnum][4]; 
			}
			else
			{
				flag = 1;
				for(ll i = 1; i <= n; i++)
				{ 
					if(a[i][4] == a[i][2])
					{
						if(minn >= a[i][4] - a[i][5])
						{
							minn = a[i][4] - a[i][5];
							minnum = i; 
						}
					}
				}
				w2--;
				num -= a[minnum][4]; 
				//cout << num << "ok\n";
				ll zscc = a[minnum][4]; 
				a[minnum][4] = a[minnum][5];
				a[minnum][5] = zscc;
				if(a[minnum][4] == a[minnum][1]) w1++;
				if(a[minnum][4] == a[minnum][2]) w2++;
				if(a[minnum][4] == a[minnum][3]) w3++;
				num += a[minnum][4];
			}
			//cout << a[minnum][4] << " " << a[minnum][5] << " " << a[minnum][6] << " " << w2 << " " << minnum << " " << num << "ok\n";
		} 
		while(w3 > n / 2)
		{ 
			if(flag) 
			{
				for(ll i = 1; i <= n; i++)
				{ 
					if(a[i][4] == a[i][3])
					{
						if(minn >= a[i][4] - a[i][6])
						{
							minn = a[i][4] - a[i][6];
							minnum = i; 
						}
					}
				}
				w3--;
				num -= a[minnum][4]; 
				ll zscc = a[minnum][4]; 
				a[minnum][4] = a[minnum][6];
				a[minnum][6] = zscc;
				if(a[minnum][4] == a[minnum][1]) w1++;
				if(a[minnum][4] == a[minnum][2]) w2++;
				if(a[minnum][4] == a[minnum][3]) w3++;
				num += a[minnum][4]; 
			}
			else
			{
				flag = 1;
				for(ll i = 1; i <= n; i++)
				{ 
					if(a[i][4] == a[i][3])
					{
						if(minn >= a[i][4] - a[i][5])
						{
							minn = a[i][4] - a[i][5];
							minnum = i; 
						}
					}
				}
				w3--;
				num -= a[minnum][4]; 
				ll zscc = a[minnum][4]; 
				a[minnum][4] = a[minnum][5];
				a[minnum][5] = zscc;
				if(a[minnum][4] == a[minnum][1]) w1++;
				if(a[minnum][4] == a[minnum][2]) w2++;
				if(a[minnum][4] == a[minnum][3]) w3++;
				num += a[minnum][4]; 
			} 
		}
		cout << num;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
