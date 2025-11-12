#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int one,two,three,tip;
}a[100005],big1[100005],big2[100005],big3[100005];
bool vis[100005];
bool cmp1(node x,node y){
	return x.one>y.one;
}
bool cmp2(node x,node y){
	return x.two>y.two;
}
bool cmp3(node x,node y){
	return x.three>y.three;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		int all1=0,all2=0,all3=0,ans=0;
		scanf("%d",&n);
		if(n==2){
			int s[5][5];
			scanf("%d%d%d",&s[1][1],&s[1][2],&s[1][3]);
			scanf("%d%d%d",&s[2][1],&s[2][2],&s[2][3]);
			int k=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(j==i) continue;
					k=max(k,s[1][i]+s[2][j]);
				}
			}
			printf("%d\n",k);
			continue;
		}else{
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i].one,&a[i].two,&a[i].three);
				a[i].tip=i;
				all1+=a[i].one;
				all2+=a[i].two;
				all3+=a[i].three;
				big1[i]=a[i];
				big2[i]=a[i];
				big3[i]=a[i];
			}
		}
		sort(big1+1,big1+n+1,cmp1);
		sort(big2+1,big2+n+1,cmp2);
		sort(big3+1,big3+n+1,cmp3);
		int i1=1,i2=1,i3=1,cnt1=1,cnt2=1,cnt3=1;
		for(int i=1;i<=n;i++){
			if(all1>=all2&&all1>=all3&&cnt1<=n/2){
				while(vis[big1[i1].tip]) i1++;
				ans+=big1[i1].one;
				vis[big1[i1].tip]=1;
				cnt1++;
				all1-=big1[i1].one;
				i1++;
			}
			else if(all2>=all1&&all2>=all3&&cnt2<=n/2){
				while(vis[big2[i2].tip]) i2++;
				ans+=big2[i2].two;
				vis[big2[i2].tip]=1;
				cnt2++;
				all2-=big2[i2].two;
				i2++;
			}
			else if(all3>=all1&&all3>=all2&&cnt3<=n/2){
				while(vis[big3[i3].tip]) i3++;
				ans+=big3[i3].three;
				vis[big3[i3].tip]=1;
				cnt3++;
				all3-=big3[i3].three;
				i3++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
