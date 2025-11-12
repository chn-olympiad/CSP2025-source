#include<bits/stdc++.h>
using namespace std;
int n,t;
int aa[100010][4];
int maxx;
void dfs(int cnt,int ii,int ca,int cb,int cc){
	if(ii==n){
		maxx=max(maxx,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&(ca+1)<=(n/2)){
			dfs(cnt+aa[ii+1][i],ii+1,ca+1,cb,cc);
		}else if(i==2&&cb+1<=n/2){
			dfs(cnt+aa[ii+1][i],ii+1,ca,cb+1,cc);
		}else if(i==3&&cc+1<=n/2){
			dfs(cnt+aa[ii+1][i],ii+1,ca,cb,cc+1);
		}
		
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int v=1;
		for(int i=1;i<=n;i++){
			cin>>aa[i][1]>>aa[i][2]>>aa[i][3];
			if(aa[i][2]!=0||aa[i][3]!=0){
				v=0;
			}
		}
		if(v==0){
			dfs(0,0,0,0,0);
			cout<<maxx<<endl;
			maxx=0;
		}else{
			sort(aa[1]+1,aa[1]+n+1);
			int cnt=0;
			for(int i=n;i>n/2;i--){
				cnt+=aa[i][1];
			}
			cout<<cnt;
		}
	}
	return 0;
}

