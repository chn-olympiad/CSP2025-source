# include <bits/stdc++.h>
# define int long long
using namespace std;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int>a;
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back((int)s[i]-(int)'0');
		}
	}
	sort(a.begin(),a.end());
	for(int i=(int)a.size()-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
