#include<bits/stdc++.h>
using namespace std;
long long t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			t[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		while(t[i]!=0){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}
