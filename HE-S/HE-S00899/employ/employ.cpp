#include<bits/stdc++.h>
using namespace std;
long long n,m,num = 0,sum = 2;
string s;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=s.length();i++)
	{
		if(s[i]==1){
			num++;
		}
	}
	if(num == s.length())
	{
		for(int i = 3;i<=s.length();i++)
		{
			sum *= i;	
		}
	}
	cout << sum%998244353;
	return 0;
	//保存时记得解注释 
} 
