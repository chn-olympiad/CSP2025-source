#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n[10]={0};
	cin>>s;
	for(int i=0;i<s.size();++i)if('0'<=s[i] && s[i]<='9')n[s[i]-'0']++;
	for(int i=9;i>=0;--i)for(int j=0;j<n[i];++j)cout<<i;
} 
