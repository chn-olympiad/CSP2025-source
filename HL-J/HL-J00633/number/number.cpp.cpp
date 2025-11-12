#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string s;
int cnt;
int a[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in",'r',"stdin");
	freopen("number.out",'w',"stdout");
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}

