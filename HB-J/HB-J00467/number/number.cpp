#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000],o;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')a[++o]=s[i];
	}
	sort(a+1;a+len+1);
	for(int i=len;i>=1;i--)printf("%d",a[i]);
	return 0;
	}
