#include<bits/stdc++.h>
using namespace std;
long long num[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int sum=0;
	int x=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
			x++;
		}
	}
	for(long long i=10;i>=0;i--){
		for(long long j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
}

