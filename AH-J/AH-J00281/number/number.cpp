#include <bits/stdc++.h>
using namespace std;
string s;
long long  arr[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long ans=s.size();
	for(long long i=0;i<ans;i++)if(s[i]>='0'&&s[i]<='9')arr[s[i]-'0']+=1;
	for(long long i=9;i>=0;i--)
		for(long long j=0;j<arr[i];j++)cout<<i;
	return 0;
}
