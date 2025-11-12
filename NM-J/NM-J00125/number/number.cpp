#include<bits/stdc++.h>
using namespace std;
string s;
int a[20]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	    if(s[i]-'0'>=0 && s[i]-'0'<=9)a[int(s[i]-'0')]++;
	for(int i=9;i>=0;i--)
	   for(int k=1;k<=a[i];k++)printf("%d",i);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
