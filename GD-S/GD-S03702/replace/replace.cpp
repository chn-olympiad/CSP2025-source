#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,Q;
string ss[200005][2],st,tt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> Q;
	for(int i=1;i<=n;i++) cin >> ss[i][0] >> ss[i][1];
	while(Q--)
	{
		ll s=0; 
		cin >> st >> tt;
		for(int i=1;i<=n;i++)
		{
			ll x=st.find(ss[i][0]),y=tt.find(ss[i][1]);
			string stt=st,ttt=tt;
			if(x==y && x!=-1 && y!=-1)
			{
				stt.erase(x,ss[i][0].size());
				ttt.erase(y,ss[i][1].size());
				if(stt==ttt) s++;
			}
		}
		cout << s <<"\n";
	}

	return 0;
}
/*
Rp++
T3Ò»Ñù¶ñÐÄ 
*/
