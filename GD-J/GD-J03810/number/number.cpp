#include<bits/stdc++.h>
using namespace std;
long long a[1000001],ss=1;
string s; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[ss]=s[i]-'0';
			ss++;
		}
	}
	sort(a+1,a+ss);
	for(int i=ss-1;i>0;i--)cout<<a[i];
	return 0;
} 
