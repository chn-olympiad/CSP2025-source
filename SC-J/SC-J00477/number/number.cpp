#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int j=9;j>=0;j--)
	for(int i=0;i<n;i++){
		if(s[i]-'0'==j)cout<<j;
	}
	return 0;
}