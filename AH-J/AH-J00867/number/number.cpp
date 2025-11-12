#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int i,j=0,ans,l,n[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=strlen(s);
	for(i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			n[j]=s[i]-48;
		}

	sort(n+1,n+j+1);
	for(i=j;i>=1;i--)
		cout<<n[i];	
	return 0;
}
