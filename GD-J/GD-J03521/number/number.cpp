#include<bits/stdc++.h>
using namespace std;
#define int long long

string s,ans;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto at:s){
		if(at>='0'&&at<='9') ans+=at;
	}
	sort(ans.begin(),ans.end(),[](auto a,auto b){
		return a>b;
	});
	cout<<ans;
	return 0;
}
