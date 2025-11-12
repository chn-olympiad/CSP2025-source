#include<bits/stdc++.h>
using namespace std;

const int N = 1E6+10;
string s;
long long num[N];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l = s.size();
	for(int i = 0; i < l+1; i++) 
	{
		if(s[i]>='0' && s[i]<='9') num[i] = s[i]-'0';
		else num[i] = -1;
	}
	sort(num,num+l,cmp);
	for(int i = 0; i < l+1; i++)
	{
		if(num[i]!=-1) cout<<num[i];
	}
	return 0;
} 
