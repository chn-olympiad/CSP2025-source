#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

string s;
const int N=15;
int a[N];
bool flag=true;

void solve(){
	cin>>s;
	int s_size=s.size();
	for(int i=0;i<=s_size-1;i++)
		if('0'<=s[i]&&s[i]>='9'){
			int x=s[i]-0;
			a[x]++;
			if(x) flag=false;
		}
	if(flag) cout<<0;
	else{
		for(int i=9;i>=0;i++)
			while(a[i]--){
				cout<<i;
			}
	}
	return;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--)
		solve();
	return 0;
}
