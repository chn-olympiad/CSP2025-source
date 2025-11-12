//1=C 4/4
#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
int mx[200005],mx2[200005],d[3][200005];
void solve(){
	int n,ca=0,cb=0,cc=0,sum=0,sum2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",a+i,b+i,c+i);
		if((a[i]>b[i])&&(a[i]>c[i])){
			mx[i]=a[i];
			ca++;
			if(b[i]>c[i])mx2[i]=b[i];
			else mx2[i]=c[i];
			d[0][ca]=mx[i]-mx2[i];
		}
		else if((b[i]>a[i])&&(b[i]>c[i])){
			mx[i]=b[i];
			cb++;
			if(a[i]>c[i])mx2[i]=a[i];
			else mx2[i]=c[i];
			d[1][cb]=mx[i]-mx2[i];
		}
		else{
			mx[i]=c[i];
			cc++;
			if(b[i]>a[i])mx2[i]=b[i];
			else mx2[i]=a[i];
			d[2][cc]=mx[i]-mx2[i];
		}
		sum2+=mx[i];//凸-_-
		//完全违反常识，什么玩意 
		sum+=max(a[i],max(b[i],c[i]));
	}
	//printf("%d %d %d\n",ca,cb,cc);
	if(ca>n/2){
		sort(&d[0][1],&d[0][ca+1]);
		for(int i=1;i<=ca-n/2;i++){
			//printf("%d ",d[0][i]);
			sum-=d[0][i];
		}
		//printf("\n");
	}
	else if(cb>n/2){
		sort(&d[1][1],&d[1][cb+1]);
		for(int i=1;i<=cb-n/2;i++){
			//printf("%d ",d[1][i]);
			sum-=d[1][i];
		}
		//printf("\n");
	}
	else if(cc>n/2){
		sort(&d[2][1],&d[2][cc+1]);
		for(int i=1;i<=cc-n/2;i++){
			//printf("%d ",d[2][i]);
			sum-=d[2][i];
		}
		//printf("\n");
	}
	//printf("%d %d %d %d\n",n/2,ca,cb,cc);
	printf("%d\n",sum);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}/*
Ren5Jie4Di4Ling5%

2211746
2527345
2706385
2710832
2861471

*/
