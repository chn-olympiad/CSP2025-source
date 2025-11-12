#include<bits/stdc++.h>
using namespace std;
char a[10000]={ };
int main()
{
	freopen("number.in""r",stdin);
	freopen("number.out""w",stdout);
	char s[100000];
	int max=0,l;
	cin>>s;
	 l=strlen(s);
	if(l==1)
	{
		 cout<<s;
	}
	for(int i=0;i<=strlen(s);i++)
	{
		 if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		 {
		     cout<<s[i];
		  } 
	           
	 }
	    	
	fclose(stdin); 
	fclose(stdout);
}
