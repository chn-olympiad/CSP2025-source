#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s; 
	for(int i=1;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z') continue;
		else a[++p]=s[i]-'0';
	}
	sort(a+1,a+1+p,greater<long long>());
	for(int i=1;i<=p;i++) cout<<a[i];
	return 0;
} 
