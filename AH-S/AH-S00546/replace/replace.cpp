#include <bits/stdc++.h>
using namespace std;
int n,q;
struct STU1
{
	string s;
}a[200005];
struct STU2
{
	string s;
}b[200005];
int main()
{
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
		cin >> a[i].s >> b[i].s;
	} 
    while(q--)
    {
		int ans = 0;
		string s3,s4;
		cin >> s3 >> s4;
		for(int i = 1; i <= n; i++)
		{
			string P = a[i].s,Q = b[i].s,R = s3;
			for(int j = 0; j < R.size(); j++)
			{
				if(R.substr(j,P.size()) == P)
				{
					R.replace(j,P.size(),Q);
					if(R == s4)
					{
						ans++;
						break;
					}
					else
					{
						R = s3;
					}
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}
