#include<bits/stdc++.h>
using namespace std;
const long long N=100000+99999;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long b[N],s=1;
	cin>>a;
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[s]=a[i]-'0';
			s++;
		}
	}
	sort(b+1,b+s);
	for(long long i=s-1;i>=1;i--)
	{
		cout<<b[i];
	}
	
	return 0;
}
