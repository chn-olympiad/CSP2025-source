#include<bits/stdc++.h>
using namespace std;
int f[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	int a=0;
	int b=s.size();
	for(int i=0; i<b; i++)
	{
		if(0<=s[i]-'0'&&s[i]-'0'<=9)
		{
			f[a]=s[i]-'0';
			a++;
		}
	}
	for(int i=0; i<a-1; i++)
	{
		for(int j=i+1; j<a; j++)
		{
			if(f[i]>f[j])
			{
				swap(f[i], f[j]);
			}
		}
	}
	for(int i=a-1; i>-1; i--)
	{
		cout<<f[i];
	}

	return 0;
}

