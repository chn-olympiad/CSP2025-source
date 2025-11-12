#include<bits/stdc++.h>
using namespace std;
int ans,n,q;
string liang[3][200005],yua,askk;
int main()
 {
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  scanf("%d%d",&n,&q);
  for(int i=1;i<=n;i++)
     {
		cin>>liang[1][i]>>liang[2][i]; 
	 }
  for(int i=1;i<=q;i++)
     {
		 cin>>yua>>askk;
		 ans=0;
		 for(int j=1;j<=n;j++)
		    {
				if(yua[yua.find(liang[1][j])==askk.find(liang[2][j])&&askk.find(liang[2][j])<askk.size()&&askk.find(liang[2][j])>=0) ans++;
			}
	     cout<<ans<<endl;
	 }
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
