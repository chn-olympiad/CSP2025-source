#include<bits/stdc++.h>
using namespace std;
long long ans;
int t,n,shu[11][100005],best[100005],gesh[11];
priority_queue<int,vector<int>,greater<int> > dui;
void gai(int a,int b,int c)
    {
	 	for(int i=1;i<=n;i++)
	 	   {
			   if(best[i]==a) {
				               int cha=min(shu[a][i]-shu[b][i],shu[a][i]-shu[c][i]);
				               dui.push(cha);
			                  }
		   }
		for(int i=1;i<=gesh[a]-n/2;i++)
		   {
			   int ding=dui.top();
			   dui.pop();
			   ans=ans-1ll*ding;
		   }
	}
int main()
 {
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  scanf("%d",&t);
  for(int qwer=1;qwer<=t;qwer++)
     {
		 ans=0;
		 memset(gesh,0,sizeof(gesh));
		 scanf("%d",&n);
		 while(dui.empty()==false) dui.pop();
		 for(int i=1;i<=n;i++)
		    {
				scanf("%d%d%d",&shu[1][i],&shu[2][i],&shu[3][i]);
				if(shu[1][i]>=shu[2][i]&&shu[1][i]>=shu[3][i]) best[i]=1;
				  else {
					     if(shu[2][i]>=shu[3][i]) best[i]=2;
					       else best[i]=3;
				       }
				gesh[best[i]]++;
				ans+=1ll*max(max(shu[1][i],shu[2][i]),shu[3][i]);
			}
		if(gesh[1]>n/2) gai(1,2,3);
		if(gesh[2]>n/2) gai(2,1,3);
		if(gesh[3]>n/2) gai(3,2,1);
		printf("%lld\n",ans);
	 }
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
