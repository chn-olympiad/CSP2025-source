#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000010],m=0;
	string s;
	cin>>s;
	int p=s.size();
	for(int i=0;i<p;i++)
    {
		if(int(s[i])>=48&&int(s[i])<=57)
		  a[m]=int(s[i])-48,m++; 
    }    
    sort(a,a+m);
    for(int i=m-1;i>=0;i--)
       cout<<a[i];
    cout<<endl;
	return 0;
}
