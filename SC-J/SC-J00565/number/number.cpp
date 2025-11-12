#include<bits/stdc++.h>
using namespace std;
const long long T=1e6+1;
string s;
long long ch[T];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long x=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 and s[i]-'0'<=9){
			ch[x]=s[i]-'0';
			x++;
		} 
	}
	sort(ch,ch+x);
	for(int i=x-1;i>=0;i--){
		cout<<ch[i];
	}
	return 0;
} 