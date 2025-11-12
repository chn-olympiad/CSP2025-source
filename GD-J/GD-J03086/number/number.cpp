#include<bits/stdc++.h>
using namespace std;
string a;
long long n,shu[1000010],m;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			shu[++m]=int(a[i]-'0');
		}
	}
	sort(shu+1,shu+1+m);
	for(int i=m;i>=1;i--)
	{
		cout<<shu[i];
	}
	return 0;
} 
