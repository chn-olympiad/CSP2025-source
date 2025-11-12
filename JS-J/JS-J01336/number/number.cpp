#include <bits/stdc++.h>
using namespace std;
string s;
int ans[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int b=s[i]-48;
			ans[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=ans[i];j>=1;j--){
			cout<<i;
		}
	}
	return 0;
}
