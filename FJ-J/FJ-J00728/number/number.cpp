#include <bits/stdc++.h>
using namespace std;
string s;
int n,e=0;
char a[1000001];
bool dod(char sw,char ws){
	return sw>ws;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i] && s[i]<='9'){
			a[e++]=s[i];
		}
	}
	sort(a,a+e,dod);
	for(int i=0;i<e;i++){
		cout<<a[i];
	}
	return 0;
}
