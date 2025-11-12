#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int main(){ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans=0,s1[11212];
	for(int i=1; i<=1005; ++i){
		if(s[i]!=' '){
			ans++;
		}
		if(s[i]%1==0){
			s1[i]+=s[i];
		}
		if(i>ans){
			break;
		}
	}
	//sort(s1+1,s1+1+1005);
	for(int i=1; i<=ans; ++i){
		cout<<s1[i];
	}
	return 0;
}
