#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
int n,b[N],j=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
    	if(isdigit(a[i]))b[j++]=a[i]-'0';
	}
	sort(b,b+n,cmp);
	for(int i=0;i<j;i++)cout<<b[i];
	return 0;
}
