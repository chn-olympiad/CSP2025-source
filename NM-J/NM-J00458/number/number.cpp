#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],n;
int main()
{  
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
   cin>>s;
     for(int i=1;i<=n;i++)
    {
	  if(a[i]>a[i-1])
     cout<<a[i];
     else  cout<<a[i-1];

}

     fclose(stdin);
    fclose(stdout);


return 0;}
