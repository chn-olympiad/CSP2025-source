#include<bits/stdc++.h>
using namespace std;
string s;
int num[20],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;len=s.size();
	for(int i=0;i<len;i++) if(s[i]<='9'&&s[i]>='0') num[s[i]-'0']++;
	for(int i=9;i>=0;i--) while(num[i]--) cout<<i;
	return 0;
}
