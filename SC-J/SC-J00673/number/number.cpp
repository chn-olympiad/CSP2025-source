#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ull unsigned long long
const int N=1e6+10;
int t[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	int tot=0;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9')t[++tot]=10-(s[i]-'0');
	}
	sort(t+1,t+1+tot);
	for(int i=1;i<=tot;i++)cout<<10-t[i];
	return 0;
}