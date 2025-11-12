#include<bits/stdc++.h>
using namespace std;
string a;
int l,b[1100001],j=0;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    l=a.size();
    for(int i=0;i<l;i++)
    {
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=a[i]-'0';
			j++;
	    } 
    }
    sort(b,b+j,cmp);
    for(int i=0;i<j;i++)
    {
		cout<<b[i];
	}
    return 0;
}
