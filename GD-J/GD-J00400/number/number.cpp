#include<bits/stdc++.h>
using namespace std;
string s;
int n,b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=sizeof(s);
	for(int i=0;i<=n-1;i++)b[i]=s[i]-'0';
	sort(b,b+n);
	for(int i=n-1;i>=0;i--)if(b[i]<=9&&b[i]>=0)cout<<b[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

