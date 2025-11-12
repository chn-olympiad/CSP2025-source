#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int q;
int n;
int a[100005][4],sum[100005],k;
int x[100005];
bool cmp(int x,int y){
	if(a[x][k]<a[x][1]||a[x][k]<a[x][2]||a[x][k]<a[x][3])return false;
	if(a[y][k]<a[y][1]||a[y][k]<a[y][2]||a[y][k]<a[y][3])return true;
	return sum[x]<sum[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&n);
		int ans=0,cnt[4];
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			x[i]=i;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans=ans+a[i][1];
				cnt[1]++;
				sum[i]=a[i][1]-max(a[i][2],a[i][3]);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans=ans+a[i][2];
				cnt[2]++;
				sum[i]=a[i][2]-max(a[i][1],a[i][3]);
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				ans=ans+a[i][3];
				cnt[3]++;
				sum[i]=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		k=0;
		if(cnt[1]>n/2)k=1;
		if(cnt[2]>n/2)k=2;
		if(cnt[3]>n/2)k=3;
		if(k)sort(x+1,x+1+n,cmp);
		int j=1;
//		cout<<cnt[k];
		while(k>0&&cnt[k]>n/2){
			cnt[k]--;
			ans=ans-sum[x[j]];
//			cout<<x[j]<<' '<<cnt[k]<<endl;
			j++;
		}
		printf("%d\n",ans);
	} 
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
