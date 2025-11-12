#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool cmp(int a,int b)
{
	return a>b;
}
string s;
int a[N],l=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
    	if(s[i]>='0'&&s[i]<='9')
           a[++l]=(s[i]-'0');   	
    sort(a+1,a+1+l,cmp);
    for(int i=1;i<=l;i++)
     	cout<<a[i];
	return 0;
}
