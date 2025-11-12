#include<bits/stdc++.h>
using namespace std;
string a;
int aa[1000010],j=0,b;
bool cmp(int a,int b)
{
	return a>b;
	}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	b=a.size();
	for(int i=0;i<=b-1;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			j++;
			aa[j]=a[i]-48;
			}
		}
	sort(aa+1,aa+j+1,cmp);
	for(int i=1;i<=j;i++)
	{
		cout<<aa[i];
		}
	}
	
	
