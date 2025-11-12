#include<bits/stdc++.h>
using namespace std;
string s;
long long mp[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long slen=s.size();
	for(long long i=0;i<slen;i++)if(s[i]>='0'&&s[i]<='9')mp[s[i]-'0']++;
	for(long long i=9;i>=0;i--)if(mp[i])for(long long j=1;j<=mp[i];j++)cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
