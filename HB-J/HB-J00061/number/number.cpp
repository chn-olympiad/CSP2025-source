//Hello! Dr.Xiong!(A great IT teacher)
//Hi! Then you're the teacher reading my code!
//Thanks to you all if I got full marks!

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[1000000000];
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string s;
	ll k;
	cin>>s;
	ll n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0' and s[i]<='9')
			x[i]=s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(x[i]<x[j] and i<j)
			{
				k=x[i];
				x[i]=x[j];
				x[j]=k;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(x[i]!=0)
			cout<<x[i]-'0';
	}
	return 0;
}
