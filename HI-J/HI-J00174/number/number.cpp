#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=1000000;
char s[N+5];
int a[N+5],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1000005);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++t]=s[i]-'0';	
	}
//	for(int i=0;i<len;i++)
//	{
//		cout<<s[i];
//		cout<<" "<<a[i]<<" "<<i<<endl;
//	}
//	cout<<t<<endl; 
	sort(a+1,a+t+1);
//	for(int i=0;i<len;i++)
//	{
//		cout<<s[i];
//		cout<<" "<<a[i]<<" "<<i<<endl;
//	}
	for(int i=t;i>=1;i--)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

