#include<bits/stdc++.h>
using namespace std;
int n[1000008];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	long long ji=0;
	for(long long i=0;i<s.size();i++){
		if(int(s[i])>=48&&int(s[i])<=57) {
			n[ji]=int(s[i])-48;
			ji++;
		}
	}
	sort(n+0,n+ji);
	for(long long i=ji-1;i>=0;i--){
		cout<<n[i];
	}
	cout<<flush;
	return 0;
} 
