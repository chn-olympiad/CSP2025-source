#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n;
vector<int> ans;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size(),s=" "+s;
	for(int i=1;i<=n;i++){
		if(isdigit(s[i]))
			ans.push_back(s[i]-48);
	} 
	sort(ans.begin(),ans.end(),cmp);
	if(ans[0]==0){
		cout<<0;
		return 0; 
	}
	for(int i=0;i<ans.size();i++)
		cout<<ans[i];
	return 0;
}
/*

I am wwqwq I AK IOI everyday

*/

