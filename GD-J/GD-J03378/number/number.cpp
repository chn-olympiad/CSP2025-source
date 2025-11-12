#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s,n=strlen(s);
	sort(s,s+n);
	for(int i=n-1;i>=0;i--)
		if(s[i]>='0'&&s[i]<='9') cout<<s[i];
	
	return 0;
}
