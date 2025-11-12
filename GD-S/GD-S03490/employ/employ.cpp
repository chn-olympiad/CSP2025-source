#include<iostream>
using namespace std;
int n;
string s;
int a;
long long cheng(int x)
{
	long long jia=1;
	for(int i=1;i<=x;i++)jia*=i;
	return jia; 
} 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
	}
	cout<<cheng(n);
}

