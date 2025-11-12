#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int mx=1e6+5;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m=0;
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if('9'>=s[i]&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	return 0;
} 