#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string s; vector<int> arr;
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			arr.push_back(int(s[i]-'0'));
	
	sort(arr.begin(),arr.end(),cmp);
	
	for(auto k:arr)
		cout<<k;
	cout<<"\n";
	return 0;
} 
