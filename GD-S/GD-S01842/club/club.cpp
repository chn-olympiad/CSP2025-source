#include<bits/stdc++.h>
using namespace std;
int a,b,n,m=0,i,j;
int club1[100001]={0},club2[100001]={0},club3[100001]={0};
int main()
{
//	//freopen("bule.in","r",stdin);
//	//freopen("clbu.in","r",stdin);

	freopen("club.in","r",stdin);
//	//freopen("culb.inout","w",stout);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
//	_sleep(500);
//return 0;
//return 0;
//return 0;
//return 0;
//return 0;
	while(t--)
	{
		cin>>n;
		int x[100001]={0};
		for(i=1;i<=n;i++)
		{
			cin>>a;
			x[i]=max(x[i],a);
		}
		m=0;
		for(i=1;i<=n;i++)
		{
			m+=x[i];
			
		}	
		cout<<m<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}























/*
  ù„ùDžÄûD 
   ûMù€ú]¸ŒúyÑ„
   ùL øJ ún
   
   ûXú–¡°øB ¡±
   ¡°øB ¡±úpúgŽw 
*/
