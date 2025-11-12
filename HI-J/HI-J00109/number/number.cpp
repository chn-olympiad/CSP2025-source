#include<bits/stdc++.h>
using namespace std;
int a[1000000];
string s,f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long i=0;
	cin>>s;
	long long x=s.size();
	for(char t:s) 
	{
		if(t>='0'&&t<='9')
		{
			a[i]=t;
			i++;
		}
	}
	sort(a,a+x);
	for(long long p=x-1;p>=0;p--)
	{
		if(a[p]!=0)
		{
			f+=a[p];
		}
	}
	cout<<f;
	return 0;
}

