#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long t=0,b=1,cnt=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
			t++;
		}
	}
	long long a[t+1];
	for(int i=0;i<=s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
		if(s[i]=='0'){
			cnt++;
		}
	}
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	for(int i=1;i<=cnt;i++){
		cout<<"0";
	}
	return 0;
} 
