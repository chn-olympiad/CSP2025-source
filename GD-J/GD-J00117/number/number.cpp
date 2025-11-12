#include<bits/stdc++.h>
using namespace std;
int a[1000];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long R=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]-'0'<=9 && s[i]-'0'>=0)a[R++]=s[i]-'0';
	}sort(a,a+R);
	while(R--)cout<<a[R];
	return 0;
}
