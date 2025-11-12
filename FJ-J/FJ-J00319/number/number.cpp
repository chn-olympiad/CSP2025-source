#include<bits/stdc++.h>
using namespace std;
string s;
int n,t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>=48 && s[i]<=57)
			t[(int)(s[i]-48)]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++)
			cout<<i;
	}
	return 0;
}

