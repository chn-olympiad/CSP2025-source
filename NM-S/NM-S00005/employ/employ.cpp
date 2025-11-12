#include<bits/stdc++.h>
using namespace std;
string s;
int a,b,a[100000];
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>a>>b;
getline(cin,s);
for(int i=1;i<=a;i++)
 cin>>a[i];
 long long ans=b%998%244%353;
 
 
cout<<ans;


fclose(stdin);
fclose(stdout);
return 0;
}
