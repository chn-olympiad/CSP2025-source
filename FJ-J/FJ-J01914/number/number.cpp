#include<bits/stdc++.h>
using namespace std;
string s;
long long t[9];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<'9'&&s[i]>='0')t[s[i]-'0']++;
		else if(s[i]=='9')cout<<9;
	}
	for(int i=8;i>=0;i--){
		for(int j=0;j<t[i];j++)cout<<i;
	}
	return 0;
}
