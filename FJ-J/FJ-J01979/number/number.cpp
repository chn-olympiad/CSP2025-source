#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int v[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int s=a.size();
	int i;
	string b="";
	for(i=0;i<s;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b=b+a[i];
		}
	}
	for(i=0;i<b.size();i++)
	{
		v[i+1]=b[i];
	}
	int t=b.size();
	sort(v+1,v+t+1);
	reverse(v+1,v+t+1);
	for(i=1;i<=b.size();i++)
	{
		char f=v[i];
		cout<<f;
	}
	return 0;
}
