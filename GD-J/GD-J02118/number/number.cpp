#include<bits/stdc++.h>

using namespace std;
string a;
vector<int> p;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.sync_with_stdio(false),cin.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')
			p.push_back((a[i]-'0'));
	
	sort(p.begin(),p.end(),greater<int>());
	
	for(int v:p)
		cout<<v;
	return 0;
} 
