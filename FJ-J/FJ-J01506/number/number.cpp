#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v;
string a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&'9'>=a[i]){
			int u=a[i]-'0';
			v.push_back(u);
		}
	}
	sort(v.begin(),v.end());
	while(v.size()){
		int u=v.back();
		v.pop_back();
		cout<<u;
	}
	return 0;
} 
