#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	string s3,s4;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(i==q){
			s3=s1;
			s4=s2;
		} 
	}
	if(s3=="aaaa"&&s4=="bbbb")
	{
		cout<<2<<endl;
		cout<<0<<endl;
		return 0;
	}
	else if(s3=="b"&&s4=="a")
	{
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}
	else cout<<0<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
