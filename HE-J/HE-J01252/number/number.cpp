#include <bits/stdc++.h>
using namespace std;
string s;
int lis[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57) lis[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<lis[i];j++){
			cout<<i;
		}
	}
	return 0;
}
