#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],x=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(a,-1,sizeof(a));
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[x++]=s[i]-'0';
	sort(a+1,a+x);
	for(int i=x-1;i>=1;i--)
		printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
