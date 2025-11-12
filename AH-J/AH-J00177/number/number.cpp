#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[1001000],c=0;
	for(size_t i=0;i<a.size();i++){
	   if(a[i]>='0'&&a[i]<='9')
	   b[++c]=a[i]-'0';
	}
	sort(b+1,b+c+1);
    for(int i=c;i>=1;i--)cout<<b[i];
	return 0;
}
