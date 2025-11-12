#include <iostream>
#include <set>
#define endl '\n'
using namespace std;
typedef long long int lli;
set<int> st = {0};
int n,k;
int a[500005],xors[500005];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		xors[i] = xors[i - 1] ^ a[i];
//		cerr << (xors[i] ^ k) << endl;
		if(st.find(xors[i] ^ k) != st.end())
		{
			ans++;
			xors[i] = 0;
			st = {};
//			cerr << "end" << endl;
		}
		st.insert(xors[i]);
	}
	cout << ans << endl;
	return 0;
}
