#include<bits/stdc++.h>
using namespace std;
string s;int t,a[9000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t++]=s[i]-'0';
		}
	}
	sort(a,a+t+1);
	for(int i=0;i<t;i++){
		cout<<a[t-i];
	}
	return 0;
}
