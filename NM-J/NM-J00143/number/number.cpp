#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long b[1000005]={};
	long long a=0;
	cin>>s;
	long long c=s.length();
	for(int i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[a]=s[i]-'0';
			a++;
		}
	}
	sort(b,b+a);
	for(int i=a-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
