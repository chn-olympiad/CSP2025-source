#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
unsigned t_now=0;
unsigned s_size;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s_size=s.size();
	for(unsigned i=0;i<s_size;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[t_now++]=s[i]-'0';
		}
	}
	sort(a,a+t_now);
	for(unsigned i=0;i<t_now;++i){
		cout<<a[t_now-i-1];
	}
	return 0;
}
