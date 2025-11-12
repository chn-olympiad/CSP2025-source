#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
string s;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	int m=n;
	for(int i=0;i<n;i++) {
		if(s[i]>='0'&&s[i]<='9') a[i+1]=s[i]-'0';
		else m--;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++) cout<<a[i];
	return 0;
}
