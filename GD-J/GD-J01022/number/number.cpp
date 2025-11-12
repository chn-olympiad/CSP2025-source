#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n,m="";
	cin >> n;
	map<char,long long> a;
	for(long long i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
			a[n[i]]++;
	}
	for(auto &as:a)
	{
		while(as.second--)
			m=as.first+m;
	}
	if(m[0]=='0')
		printf("0");
	else
		cout << m;
	return 0;
}
