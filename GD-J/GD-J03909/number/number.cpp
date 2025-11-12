#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
string str;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0'&&str[i]<='9')
			v.push_back((ll)(str[i]-'0'));
	sort(v.begin(),v.end());
	while(v.size()>1)
		if(v.back()==0)
			v.pop_back();
		else
			break;
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
	return 0;
}

