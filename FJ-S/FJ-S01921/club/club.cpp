#include <bits/stdc++.h>
using namespace std;
int a[100005][4];long long mym = 0;
int n,t;
int clo[100005],cnt[4],sub[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n;
		for (int j = 1;j <= n;j++)
		{
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			int myuu = 0,iidx = 0;
			for (int k = 1;k <= 3;k++)
			{
				if (a[j][k] > myuu) 
				{
					myuu = a[j][k];
					iidx = k;
				}
			}
			mym+=myuu;
			clo[j] = iidx;
			cnt[iidx]++;
		} 
		//for (int ooo = 1;ooo <= 3;ooo++) cout << cnt[ooo] << " " <<endl;
		for (int lo = 1;lo <= 3;lo++) 
		{
			if (cnt[lo] > n/2)
			{
				//cout << "p";
				int w = 1;
				for (int so = 1;so <= n;so++)
				{
					if (clo[so] == lo)
					{
						if (lo == 1) sub[w] = min(a[so][1]-a[so][2],a[so][1]-a[so][3]);
						if (lo == 2) sub[w] = min(a[so][2]-a[so][1],a[so][2]-a[so][3]);
						if (lo == 3) sub[w] = min(a[so][3]-a[so][1],a[so][3]-a[so][2]);
						w++;	
					}
				}
				//cout << w << endl; 
				//cout << sub[1] <<" " <<sub[2] << " "<<sub[3]<<endl;
				sort(sub+1,sub+w);
				//cout << sub[1] <<" " <<sub[2] << " "<<sub[3]<<endl;
				
				for (int ppo = 1;ppo <= cnt[lo]-n/2;ppo++)
				{
					mym-=sub[ppo];
				}
			}
		}

		cout << mym << endl;
		mym=0;
		memset(clo,0,sizeof(clo));
		memset(cnt,0,sizeof(cnt));
		memset(sub,0,sizeof(sub));
	} 
	return 0;
} 
