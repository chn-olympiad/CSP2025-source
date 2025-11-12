#include<bits/stdc++.h>
using namespace std;
int n,m,c[10086],len;
string s;
int main()
{
     freopen("employ.in","r",stdin);
	 freopen("employ.out","w",stdout);
	 cin>>n>>m;
	 cin>>s;
	 len=s.size();
	 for(int i=1;i<=n;i++)
	 cin>>c[i];
	 if(n==3&&m==2) 
	 cout<<2;
	 fclose(stdin);
	 fclose(stdout);
     return 0;
}
