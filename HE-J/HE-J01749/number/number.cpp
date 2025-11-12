#include<bits/stdc++.h>
using namespace std;
char a(int x)
{
	char s[1000];
	for(int i=0;i<x;i++)
	{
		cin>>s[i];
		if(s[i]==1||s[i]==2||s[i]==3||s[3]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9)
		{
			return s[i];
		}else{
			break;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cout<<a(5);
	frclose(stdin);
	frclose(stdout);
	return 0;
}
