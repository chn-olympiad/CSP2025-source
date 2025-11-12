#include<bits/stdc++.h>
using namespace std;
int a[1000000];
string str1="abcdefghijklmnopqrstuvwxyz",s;
int main()
{
	//freopen("number.in",r,stdin);
	//freopen("number.out",w,stdout);
	int num1=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(int(s[i]-'0')>=0 && int(s[i]-'0')<=10)
		{
			a[num1]=int(s[i]-'0');
			num1++;
			}
	}
	for(int j=0;j<num1;j++){
		for(int x=j;x<num1;x++){
			if(a[j]<a[x]){
				swap(a[x],a[j]);
				}
			}
		}
	for(int a1=0;a1<num1;a1++)
	{
		cout<<a[a1];
	}
	return 0;
}
