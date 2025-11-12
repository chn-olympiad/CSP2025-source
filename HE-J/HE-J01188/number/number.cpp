#include<bits/stdc++.h>
using namespace std;
string s;
long long a[99999999],b;
bool cmp(long long a,long long b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++b]=s[i]-'0';
		}
	}
	sort(a+1,a+1+b,cmp);
	if(a[1]==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=b;i++){
		cout<<a[i];
	}
	
	return 0;
}
