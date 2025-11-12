#include<bits/stdc++.h>
using namespace std;
int a[100005][4],max1[100005],tot[4];
struct node{
	int id,num;
}s[4][100005];
struct node2{
	int type,id,num;
}g[100005];
bool cmp(node2 u,node2 v){
	return u.num>v.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,f=0;
		long long ans=0;
		scanf("%d",&n);
		memset(max1,-1,sizeof(max1));
		tot[1]=tot[2]=tot[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int x;
			for(int j=1;j<=3;j++){
				if(a[i][j]>max1[i]){
					x=j;
					max1[i]=a[i][j];
				}
			}
			tot[x]++;
			s[x][tot[x]].id=i;
			s[x][tot[x]].num=max1[i];
		}
		for(int i=1;i<=3;i++){
			if(tot[i]>n/2){
				for(int j=1;j<=tot[i];j++){
					int max2=1000000,y,e=s[i][j].id;
					for(int k=1;k<=3;k++){
						if(k!=i&&max1[e]-a[e][k]<max2){
							max2=max1[e]-a[e][k];
							y=k;
						}
					}
					g[j].type=y;
					g[j].id=e;
					g[j].num=max2;
				}
				sort(g+1,g+tot[i]+1,cmp);
				for(int j=1;j<=n/2;j++) ans+=max1[g[j].id];
				for(int j=n/2+1;j<=tot[i];j++) ans+=(max1[g[j].id]-g[j].num);
				for(int j=1;j<=3;j++)
					if(j!=i){
						for(int k=1;k<=tot[j];k++) ans+=s[j][k].num;
					}
				f=1;
				break;
			}
		}
		if(f==0){
			for(int i=1;i<=n;i++) ans+=max1[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
