#include <bits/stdc++.h>
using namespace std;
int t,n,m,num[10];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i]))num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		//cout<<num[i]<<' ';
		for(int j=1;j<=num[i];j++)cout<<i;
	}
	return 0;
}