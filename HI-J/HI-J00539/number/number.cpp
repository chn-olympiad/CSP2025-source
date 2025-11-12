#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a;
string s; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int u=s.size();
	int h=1;
	for(int i=0;i<u;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[h]=s[i];
			h++;
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=h-1;j++)
		{
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=h;i++){
		cout<<a[i];
	}
	return 0;
}


