#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n;
map<int,int>a;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	return 0;
}
/*
99998888887777766666655555544444433332111000000000

*/