#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	s=" "+s;
	for (int i=1;i<=n;i++){
		if (s[i]-'0'<=9 && s[i]-'0'>=0) ans.push_back(s[i]-'0');
	}
	sort(ans.begin(),ans.end(),cmp);
	for (int i:ans) cout<<i;
	cout<<endl;
	return 0;
}
