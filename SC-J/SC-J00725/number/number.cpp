#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		long long x=s[i]-'0';
		if(x>=0&&x<=9)a[x]++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	return 0;
}