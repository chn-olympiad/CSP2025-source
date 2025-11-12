#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int N=60000;
int n,w[N],ans=0;

void sfd(int ti,int tj,int goal,int k){
	if(tj>goal) ans+=1;
	if(ti>k){
		return ;
	}
	
	
		
	

	sfd(ti+1,tj+w[ti],goal,k);
	sfd(ti+1,tj,goal,k);
	}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		}

	for(int i=3;i<=n;i++){
		int max=-1;
		for(int i=1;i<=n;i++)
		if(w[i]>max)max=w[i];
		sfd(1,0,max,i-1);
		}
	printf("%d",ans);
	return 0;
}


