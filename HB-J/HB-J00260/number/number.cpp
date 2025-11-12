#include<iostream>
#include<string.h>
using namespace std;
string s;
bool emp;
int n[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i];i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
		if(s[i]>='1')emp=1;
		n[s[i]-'0']++;
		}
	}
	if(!emp){
		cout<<0;
		return 0;
		}
	for(int i=9;i>=0;i--){
		while(n[i]--)
			printf("%d",i);
		
		}
	
	


	return 0;
}
