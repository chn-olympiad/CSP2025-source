#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
char s[N];
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	int j=0;
	int k=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			j++;
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}

