#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],ans,tans,n2num;
struct fkccf{
	int v12,v13,v23,id;
};
bool cmp1(fkccf a,fkccf b){
	if(a.v12!=b.v12) return a.v12>b.v12;
	else return a.v13+a.v23<b.v13+b.v23;
}
bool cmp2(fkccf a,fkccf b){
	return a.v13>b.v13;
}
void dfs(int i,int sum,int n1,int n2,int n3){
	if(i==n+1){
		ans=max(ans,sum);
		return ;
	}else{
		if(n1<(n/2)) dfs(i+1,sum+a[i][1],n1+1,n2,n3);
		if(n2<(n/2)) dfs(i+1,sum+a[i][2],n1,n2+1,n3);
		if(n3<(n/2)) dfs(i+1,sum+a[i][3],n1,n2,n3+1);
		return ;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		fkccf d1[n+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
			d1[i]={a[i][2]-a[i][1],a[i][3]-a[i][1],a[i][3]-a[i][2],i},tans+=a[i][1];
		}
		if(n<=10){
			dfs(1,0,0,0,0);
		}else{
			sort(d1+1,d1+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					tans+=d1[i].v12;
					d1[i].v13=d1[i].v23;
					d1[i].v23=-1145141919,n2num++;
				}
			}
			sort(d1+1,d1+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				if(d1[i].v13>0){
					tans+=d1[i].v13;
					d1[i].v12=-1145141919;
					if(d1[i].v23==-1145141919) n2num--;
				}
				else break;
			}
			sort(d1+1,d1+1+n,cmp1);
			for(int i=1;i<=(n/2-n2num);i++){
				if(d1[i].v12>0 && d1[i].v23!=-1145141919){
					tans+=d1[i].v12;
				}
			}
		}
		if(n<=10) cout << ans << endl;
		else cout << tans << endl;
		ans=0,n2num=0,tans=0;
	}
	return 0;
}
