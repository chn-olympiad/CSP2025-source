//freopen
#include<bits/stdc++.h>
using namespace std;
char s[100000005];
long long a[10000005],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	scanf("%s",s);
	long long len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
