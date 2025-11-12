#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	vector<int>ans;
	int n=0;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans.push_back(s[i]-'0');
			n++;
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=n-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
} 
