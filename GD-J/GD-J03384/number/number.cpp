#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)if(isdigit(s[i]))num[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(num[i]--)cout<<i;
	}
	return 0;
} 
