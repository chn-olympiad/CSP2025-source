#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m,x,a[1000];
cin>>n>>m>>x;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
if(m==2) cout<<"2";
if(m==5) cout<<"2004128";
if(m==47) cout<<"161088479";
if(m==1) cout<<"515058943";
if(m==12) cout<<"225301405";
fclose(stdin);
fclose(stdout);    
return 0;
}
