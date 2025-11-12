#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000006
ll a[N],top; 
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s,s=" "+s;
	for(int i=1;i<s.length();i++) if(s[i]>='0'&&s[i]<='9') a[++top]=s[i]-'0';
	sort(a+1,a+top+1);
	for(int i=top;i;i--) cout<<a[i];
	cout<<endl;
	return 0;
}
