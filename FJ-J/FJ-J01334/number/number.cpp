#include<bits/stdc++.h>
using namespace std;
string s;
int p[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len;++i) if(s[i]>='0' && s[i]<='9') p[s[i]-'0']++;
	for(int i=9;i>=0;--i) if(p[i]) for(int j=1;j<=p[i];++j) cout<<i;
	return 0;
}
