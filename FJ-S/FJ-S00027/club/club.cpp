#include<bits/stdc++.h>
using namespace std;
const int T=1e5+10;
int a[T][4],b[T];
int ans=0,sum=0;
int n;
void qwq(int a1,int a2,int a3,int n0){
	if(n0==n) ans=max(ans,sum);
	else{
		n0++;
		if(a1<n/2){
			a1++;
			sum+=a[n0][1];
			qwq(a1,a2,a3,n0);
			sum-=a[n0][1];
			a1--;
		}
		if(a2<n/2){
			a2++;
			sum+=a[n0][2];
			qwq(a1,a2,a3,n0);
			sum-=a[n0][2];
			a2--;
		}
		if(a3<n/2){
			a3++;
			sum+=a[n0][3];
			qwq(a1,a2,a3,n0);
			sum-=a[n0][3];
			a3--;
		}
	}
}
void wqw(int a1,int a2,int n0){
	if(n0==n) ans=max(ans,sum);
	else{
		n0++;
		if(a1<n/2){
			a1++;
			sum+=a[n0][1];
			wqw(a1,a2,n0);
			sum-=a[n0][1];
			a1--;
		}
		if(a2<n/2){
			a2++;
			sum+=a[n0][2];
			wqw(a1,a2,n0);
			sum-=a[n0][2];
			a2--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int Q=1;Q<=t;Q++){
		bool p1=1,p2=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0) p1=0;
			if(a[i][3]!=0) p2=0;
			b[i]=a[i][1];
			int u=i;
			while(b[u]>b[u-1]&&u>1){
				swap(b[u],b[u-1]);
				u--;
			}
		}	
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;i<=3;i++){
					if(j==i) continue;
					ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			printf("%d\n",ans);
		}
		else if(p1&&p2){
			for(int j=1;j<=n/2;j++){
				ans+=b[j];
			}
			printf("%d\n",ans);
		}
		else if(p2){
			wqw(0,0,0);
			printf("%d\n",ans);
			ans=0;
		}
		else{
			qwq(0,0,0,0);
			printf("%d\n",ans);
			ans=0;
		}
	}
	return 0;
}
