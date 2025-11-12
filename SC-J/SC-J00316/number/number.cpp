#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string st;
int a[1000005],a1[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	int j=0;
	for (int i=0;i<st.size();i++)
	    if (st[i]>='0' && st[i]<='9')
	    {
	    	j++;
	    	a[j]=int(st[i])-48;
		}
	sort(a+1,a+j+1);
	for (int k=1;k<=j;k++) a1[k]=a[j-k+1];
	for (int k=1;k<=j;k++) cout<<a1[k];
	return 0;
}