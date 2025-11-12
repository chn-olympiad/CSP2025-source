#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int n;
char ch[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9') ch[++n]=s[i];
	}
	sort(ch+1,ch+n+1);
	reverse(ch+1,ch+n+1);
	if(ch[1]=='0'){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cout<<ch[i];
	}
	return 0;
}
