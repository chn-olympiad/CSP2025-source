#include <bits/stdc++.h>
using namespace std;
int a[10][100005],t[5],n,T,e,r;
long long ans;
vector <int> p[10];
vector <pair<int,int> > l;
bool cmp(pair<int,int> x, pair<int,int> y)
{
	return x.first>y.first;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
	    int k = n / 2;
    	for(int i = 1; i <= n; i++)
    	{
	    	cin >> a[1][i] >> a[2][i] >> a[3][i];
	    	int maxx1=0,pos1=0;
	    	for(int j = 1; j <= 3; j++)
	    	{
	    		if(a[j][i]>maxx1)
	    		{
	    			maxx1 = a[j][i];
	    			pos1 = j;
				}
			}
			ans += maxx1;
			p[pos1].push_back(i);
	    }
	    for(int i = 1; i <= 3; i++)
	    {
	    	t[i] = p[i].size();
	    	if(t[i]>k)
	    	{
	    		for(int j = 0; j < p[i].size(); j++)
	    		{
	    			int maxx = INT_MIN,pos=0;
	    			for(int o = 1; o <= 3; o++)
	    			{
	    				if(o==i)
	    				{
	    					continue;
						}
						if(a[o][p[i][j]] - a[i][p[i][j]]>maxx)
						{
							maxx = a[o][p[i][j]] - a[i][p[i][j]];
							pos = o;
						}
					}
					l.push_back({maxx,pos});
				}
				sort(l.begin(),l.end(),cmp);
	    	    for(int j = 0; j < l.size(); j++)
	        	{
	    	     	t[l[j].second]++;
	    	     	if(t[l[j].second]>k)
	    	     	{
	    	     		t[l[j].second]--;
	    	     		continue;
					}
					ans += l[j].first;
					t[i]--;
					if(t[i]<=k)
					{
						break;
					}
		    	}
			}
		}
		cout << ans << endl;
		ans = 0;
		l.clear();
		memset(t,0,sizeof(t));
		p[1].clear();
		p[2].clear();
		p[3].clear();
	}
	return 0;
}
