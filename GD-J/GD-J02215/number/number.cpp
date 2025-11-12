#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	cin>>s+1;
	n=strlen(s+1);
	int k=0;
	for(int i=1;i<=n;i++)if(s[i]>='0'&&s[i]<='9')a[++k]=s[i]-'0';
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)cout<<a[i];
	return 0;
}
