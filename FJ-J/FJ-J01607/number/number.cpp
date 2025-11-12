#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int tot,a[1000010];
string s;
void solve(){
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1);
	for(int i=tot;i>0;i--)
		cout<<a[i];
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	//cin>>num;
	while(num--)solve();
	return 0;
}
