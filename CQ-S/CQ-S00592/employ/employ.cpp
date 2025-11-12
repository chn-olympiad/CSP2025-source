#include<bits/stdc++.h>
using namespace std;
const int N=510, mod=998244353;
//next_permuction 
int n, m;
string s;
int ans;
int lose;
int c[N];
int cnt;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++)
		cin>>c[i];
	sort(c+1, c+n+1);
	for(int i=0; i<s.size(); i++){
		if(s[i]=='0' || c[i+1]<=lose) lose++;
		else ans++;
	}
	cnt++;
	while(true){
		ans=0;
		next_permutation(c+1, c+n+1);
		for(int i=1; i<=n; i++){
			if(s[i]=='0' || c[i+1]<=lose) lose++;
			else ans++;
		}
		if(ans>=m) cnt++, cnt%=mod;
		else break;
	}
	cout<<cnt;
	return 0;
}
