#include<iostream>
#include<algorithm>
using namespace std;
const int si=1e5+10;
int n,a[si][4],b[si],v[si];
int mx[si],nm,ans;
int c[4];
int mian(){
	scanf("%d",&n),nm=ans=c[1]=c[2]=c[3]=0;
	for(int i=1;i<=n;i++){
		int mx=0,mi=0,sx=0;
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>mx)sx=mx,mx=a[i][j],mi=j;
			else if(a[i][j]>sx)sx=a[i][j];
		}ans+=mx,c[mi]++,b[i]=mi,v[i]=mx-sx;
	}for(int i=1;i<=3;i++)
		if(c[i]>n/2){
			for(int j=1;j<=n;j++)
				if(b[j]==i)mx[++nm]=v[j];
			sort(mx+1,mx+nm+1);
			for(int j=1;j<=c[i]-n/2;j++)
				ans-=mx[j];
		}
	printf("%d\n",ans);
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)mian();
	return 0;
}
