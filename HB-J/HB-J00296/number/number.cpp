#include <bits/stdc++.h>
using namespace std;
int n,s;
int w[1005];
bool f(int s,int z)
{
	return s>z;
}
int main()
{
        freopen("number.in","r",stdin);
        freopen("number.out","n",stdout);
	cin >> a;
	for(int i=1;i<=a.size();i++)
	{
	
	    if(a[i]>='0';&&a[i]<='9')
	    {
		w[i]=a[i];
		n++;
            }
	}
	sort(w+1,w+n+1,f);
	for(int i=1;i<=n;i++)
	{
		cout <<a[i];
		}
	return 0;
}
