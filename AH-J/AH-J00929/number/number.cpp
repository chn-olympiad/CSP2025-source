#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if('0'<=s[i] and s[i]<='9')a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	puts("");
}
