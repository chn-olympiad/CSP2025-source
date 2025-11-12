#include<bits/stdc++.h>
using namespace std;

string s;
int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	n=s.size();
	s=' '+s;
	vector<char> ans;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9')
			ans.push_back(s[i]);
	} 
	sort(ans.begin(),ans.end(),[&](char a,char b)->bool{
		return int(a)>int(b);
	});
	for(int i=0;i<ans.size();i++)
		cout<<ans[i];
	return 0;
} 