#include<bits/stdc++.h>
using namespace std;
long long k=0,n,m,p,a[10000001];
string s;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.length();
    for(int i=1;i<=n;i++){
		if(s[i]=='1')a[++p]=1;
		if(s[i]=='2')a[++p]=2;
		if(s[i]=='3')a[++p]=3;
		if(s[i]=='4')a[++p]=4;
		if(s[i]=='5')a[++p]=5;
		if(s[i]=='6')a[++p]=6;
		if(s[i]=='7')a[++p]=7;
		if(s[i]=='8')a[++p]=8;
		if(s[i]=='9')a[++p]=9;
		if(s[i]=='0')a[++p]=0;
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++) cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
