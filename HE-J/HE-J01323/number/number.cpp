#include<bits/stdc++.h>
using namespace std;
const int n=1e7;
string l;
int a[n];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s=1;
	getline(cin,l);
	int t=l.size();
	while(t--)
	{
		
		if(l[t]>='0'&&l[t]<='9')
		{
			a[s]=l[t]-'0';
			s++;
		}
		
	}
	sort(a+1,a+s+1);
	for(int i=s;i>1;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
