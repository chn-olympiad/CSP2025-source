#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5;

char s[N];
int n,a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s);
	
	int sz=strlen(s);
	for(int i=0;i<sz;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++n]=(int)(s[i]-'0');
	
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)
		printf("%d",a[i]);
	return 0;
}
