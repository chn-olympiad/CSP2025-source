#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=1e5+10;
const int maxm=1e6+10;
const int mod=1e9+7;
int n;
string s,ss;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> s;
	n=s.size();
	for (int i=0;i<n;i++) if (s[i]>='0'&&s[i]<='9') ss+=s[i];
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	if (ss[0]=='0') cout << 0;
	else cout << ss; 
	return 0;
}
/*
8：30 开题！
8：40 搞完文件夹了
8：45 T1唐，AC 
8：56 T2唐，AC
9：09 T3唐，AC
9：25 T4大样例过掉了，对拍！
9：31 T4拍完了
wlwlwlwlwlwlwlwlwlwlwlwlwl 
9：43 摸鱼被邓大质问了 
9：52 surf和dino都被禁了，太毒了 (-_-)，只能玩python，张队好像也写完了
CSP-J 2025 RP++!
*/
