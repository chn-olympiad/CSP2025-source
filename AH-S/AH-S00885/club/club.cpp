#include<bits/stdc++.h>
using namespace std;
int T,N,cnt[5];
struct node{
	int A[5],id[5];
	int c;
}stu[100010];
bool cmp(node x,node y){
	return x.c>y.c;
}
void init(){
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=100000;i++){
		stu[i].c=0;
		for(int j=0;j<=4;j++)
			stu[i].A[j]=stu[i].id[j]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			scanf("%d%d%d",&stu[i].A[1],&stu[i].A[2],&stu[i].A[3]);
			stu[i].id[1]=1,stu[i].id[2]=2,stu[i].id[3]=3;
			for(int x=1;x<3;x++)
				for(int y=x+1;y<=3;y++)
					if(stu[i].A[x]<stu[i].A[y]){
						swap(stu[i].A[x],stu[i].A[y]);
						swap(stu[i].id[x],stu[i].id[y]);
					}
			stu[i].c=stu[i].A[1]-stu[i].A[2];
		}
		sort(stu+1,stu+1+N,cmp);
		long long ans=0;
		for(int j=1;j<=N;j++){
			if(cnt[stu[j].id[1]]+1<=N/2){
				ans+=stu[j].A[1];
				cnt[stu[j].id[1]]++;
			}
			else{
				ans+=stu[j].A[2];
				cnt[stu[j].id[2]]++;
				}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
