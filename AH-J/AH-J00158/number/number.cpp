#include<bits/stdc++.h>
using namespace std;
int a[10],n;
string s;
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(a,0,sizeof(a));
	n=s.size();
	for(int i=0;i<n;i++)
		if (s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]--) {printf("%d",i);}
	return 0;
}
