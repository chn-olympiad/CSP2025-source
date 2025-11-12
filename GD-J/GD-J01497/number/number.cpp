#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string s;
long long a[1000010],siz;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i = 0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0'] ++;
		}
	}
	for(long long i = 9;i>=0;i--){
		if(a[i]){
			cout<<string(a[i],i+'0');
		}
	}
	return 0;
} 
