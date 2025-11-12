#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
   cin>>n;
   for(int i=0;i<=s.length();i++)
   {
   	 if(s[i]>='0'&&s[i]>='9')
   	 {
   	 	n++;
   	 	int x=s[i]-'0';
   	 	a[n]-x;
		}
   }
   sort(a+1,a+n+1);
   for(int i=n;i>=1;i--)
     cout<<a[i];
fclose(stdin);
fclose(stdout);
return 0;
}
