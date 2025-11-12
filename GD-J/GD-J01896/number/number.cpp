 #include<bits/stdc++.h>
 using namespace std;
 const int N=1e6+5;long long a[N];
 int main()
 {
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	string s;
 	cin>>s;
 	for(long long i=0;i<s.size();i++)
 	{
 	if(s[i]>='0'&&s[i]<='9')
	a[s[i]-'0']++;	
	}
	for(long long i=9;i>=0;i--)
 	{
 	for(long long j=0;j<a[i];j++)
 	cout<<i;
	}
 	return 0;
 }
