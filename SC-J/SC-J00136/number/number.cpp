#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n[10]={0},len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
}