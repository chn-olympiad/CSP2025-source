#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
char s[N];
int len,sum[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if(s[i]>='0'&&s[i]<='9'){
			int num=s[i]-'0';
			sum[num]++;
		}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=sum[i];j++)
			cout<<i;
	return 0;
}