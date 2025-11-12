#include<bits/stdc++.h>
using namespace std;
int a[100005],t=0;
string s;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++t]=(int)(s[i]-'0');
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;++i)
		printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
