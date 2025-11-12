#include<bits/stdc++.h>
using namespace std;
struct person{
	int s,id,dep;
};
bool cmp1(person x,person y){
	return x.s<y.s;
}
bool cmp2(person x,person y){
	return x.s>y.s;
}
int t,n,ans,a_[100005][4];
person a[100005][4],d[4][50005];
int r[4];
void dfs(int i,int r1,int r2,int r3,int stsf){
	if(i==n+1){
		ans=max(ans,stsf);
		return;
	}
	if(r1>0) dfs(i+1,r1-1,r2,r3,stsf+a_[i][1]);
	if(r2>0) dfs(i+1,r1,r2-1,r3,stsf+a_[i][2]);
	if(r3>0) dfs(i+1,r1,r2,r3-1,stsf+a_[i][3]);
}
void place(int who,int which){
	int rank=a[who][which].dep;
		if(r[rank]<n/2){
			ans+=a[who][which].s;
			r[rank]++;
			d[rank][r[rank]]=a[who][which];
		}
		else{
			sort(d[rank]+1,d[rank]+r[rank]+1,cmp1);
			if(a[who][which].s>d[rank][1].s){
				int temp=d[rank][1].id;
				ans-=a[temp][which].s;
				ans+=a[who][which].s;
				d[rank][1]=a[who][which];
				place(temp,which+1);
			}
			else place(who,which+1);
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a_[i][j]);
				a[i][j].s=a_[i][j];
				a[i][j].id=i;
				a[i][j].dep=j;
			}
			sort(a[i]+1,a[i]+4,cmp2);
		}
		ans=0;
		if(n>10){
			r[1]=r[2]=r[3]=0;
			memset(d,0,sizeof(d));
			for(int i=1;i<=n;i++) place(i,1);
		}
		else dfs(1,n/2,n/2,n/2,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
