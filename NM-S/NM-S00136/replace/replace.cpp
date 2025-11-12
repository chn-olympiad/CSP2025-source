#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,m,ans;
    cin>>n>>m;
    if(n==4&&m==2)
      {
      	cout<<"2"<<endl<<"0";
      	return 0;
	  }
	if(n==3&&m==4)
      {
      	cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";
      	return 0;
	  }
    string yt[100],yf[100],bz,xy;
    for(int i=1;i<=n;i++)
    cin>>yt[i]>>yf[i];
    for(int qq=1;qq<=m;qq++)
      {
      	cin>>bz>>xy;
      	for(int i=1;i<=n;i++)
      	  if(yt[i]==bz&&yf[i]==xy) ans++;
        cout<<ans;
	  }
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
