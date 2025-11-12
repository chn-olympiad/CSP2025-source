#include <bits/stdc++.h> 
using namespace std;
const int MAX=1000005;
string s;
int cnt=0,t;
int a[MAX];
int main(){
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if ((s[i]-'0')/10==0)
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=0;i<cnt/2;i++)
	{
		t=a[i];
		a[i]=a[cnt-i-1];
		a[cnt-i-1]=t;
	}
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}

