#include<iostream>
#include <string>
#include <algorithm>
#include <cstdio> 
using namespace std;

 string a;
 int b[1005];
 bool cmp(int x,int y)
 {
 	return x>y;
 }
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
    int n = a.size(),m=0;
    for(int i=0;i<n;i++)
    {
     if('0'<=a[i]&&a[i]<='9')
     {
        b[i] = a[i]-'0';
        m++;
     }
    }
    sort(b+0,b+0+n,cmp);
    for (int i=0;i<m;i++)
    {
        cout<< b[i];
    }
    return 0;
}
