#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int ns[1000005];
int ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf ("%s",s+1);
	int l = strlen (s+1);
	int ls = 0;
	for (int i=1;i<=l;i++)
	    if (s[i]>='0'&&s[i]<='9')
	        ns[++ls] = s[i]-'0';
	sort(ns+1,ns+ls+1);
	for (int i = ls;i>=1;i--){
		ans*=10;
		ans+=ns[i];
	}
	printf ("%d\n",ans);
}
