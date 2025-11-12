#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e2+3;
struct no{
	int x,y,z;
}a[N];
int t,n;
int b[4],ans;
int f[N][202][202];
int flag=0,flag2=0;
bool cmp(no a,no b){
	return (a.x-a.y)>(b.x-b.y);
}
bool cmp2(no a,no b){
	return a.x>b.x;
}
void solve(){
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].x;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=a[i].y;
	}
	printf("%d\n",ans);
}
void solve1(){
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].x;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0; 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z); 
			if(a[i].z)flag=1;
			if(a[i].y||a[i].z)flag2=1;
		}
		if(flag2==0){
			solve1();
			continue;
		}
		else if(flag==0){
			solve();
			continue;
		}
		else {
			memset(f,128,sizeof f);
			f[0][0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(f[i-1][j][k]>=0){
							if(j<n/2)f[i][j+1][k]=max(f[i][j+1][k],f[i-1][j][k]+a[i].x);
							if(k<n/2)f[i][j][k+1]=max(f[i][j][k+1],f[i-1][j][k]+a[i].y);
							if(i-j-k-1<n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
						}
					}
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=0;j<=n/2;j++){
//					for(int k=0;k<=n/2;k++){
//						if(f[i][j][k]>-1)cout<<f[i][j][k]<<" ";
//						else cout<<"e ";
//					}
//					cout<<endl;
//				}
//				cout<<"---------------------------\n";
//			}
			int ans=-1;
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					ans=max(ans,f[n][j][k]);
				}
			}
			printf("%d\n",ans);
			continue;
		}
	}
	return 0;
} 

