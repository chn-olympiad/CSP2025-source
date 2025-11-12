#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),cnt=0;
	for(int i=0;i<len;i++)if(s[i]<='9'&&s[i]>='0')a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
} 
