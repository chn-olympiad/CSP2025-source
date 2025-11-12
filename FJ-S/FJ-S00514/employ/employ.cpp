#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1') cnt++;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
