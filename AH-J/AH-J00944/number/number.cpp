#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string s;
long long a[1000000],t=1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}	
	sort(a+1,a+t,cmp);
	for(int i=1;i<t;i++){
		cout<<a[i];
	}
	return 0;
}
