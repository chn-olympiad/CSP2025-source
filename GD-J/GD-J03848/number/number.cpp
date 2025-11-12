#include<bits/stdc++.h>
using namespace std;
string s;
long long d[1000005],di;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') d[++di]=s[i]-'0';
	sort(d+1,d+di+1,greater<int>());
	for(int i=1;i<=di;i++) printf("%lld",d[i]);
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
