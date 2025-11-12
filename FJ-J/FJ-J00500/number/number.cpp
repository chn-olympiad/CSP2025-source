#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			++t;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t,greater<int>());
	for(int i=1;i<=t;++i) cout<<a[i];
	return 0;
}
