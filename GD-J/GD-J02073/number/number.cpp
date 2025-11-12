#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int num[N];
int len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			num[++len]=s[i]-'0';
		}
	}
	sort(num+1,num+len+1,greater<int>());
	for(int i=1;i<=len;++i){
		cout<<num[i];
	}
	return 0;
} 
