#include <bits/stdc++.h>
using namespace std;
#define ll long long
int zh[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int l=s.length(),szh=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			zh[szh++]=s[i]-'0';
		}
	}
	sort(zh,zh+szh);
	if(zh[szh-1]==0){
		cout<<"0";
		return 0;
	}
	for(int i=szh-1;i>=0;i--){
		cout<<zh[i];
	}
	return 0;
}
