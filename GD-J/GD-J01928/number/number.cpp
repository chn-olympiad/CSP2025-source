#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+100;
string s;
int n,a[N],k;
bool cmp(int a1,int a2)
{
	return a1>a2;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[++k]=s[i]-'0'; 
	}
	sort(a+1,a+k+1,cmp);
	if(!a[1])
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=k;i++) cout<<a[i];
	return 0;
} 
