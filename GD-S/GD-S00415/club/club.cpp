#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,ans,cant,vis[N];
int a[N],b[N],c[N];
int club[3];
void dfs(int man,int all,int have){
	if(have>=n){ans=max(ans,all);
		return;
	}
	/*for(int i=0;i<3;i++){
		if(club[i]<cant){
			club[i]++;
			if(!i)dfs(man%n+1,all+a[man],have+1);
			else if(i==2)dfs(man%n+1,all+b[man],have+1);
			else dfs(man%n+1,all+c[man],have+1);
			club[i]--;
		}
	}*/
	int mm=man%n;
	if(club[0]<cant){
		club[0]++;
		dfs(mm+1,all+a[man],have+1);
		club[0]--;
	}
	if(club[1]<cant){
		club[1]++;
		dfs(mm+1,all+b[man],have+1);
		club[1]--;
	}
	if(club[2]<cant){
		club[2]++;
		dfs(mm+1,all+c[man],have+1);
		club[2]--;
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		cant=(n>>1);
		for(i=1;i<=n;i++){
			scanf("%d %d %d",a+i,b+i,c+i);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			dfs(i,0,0);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
