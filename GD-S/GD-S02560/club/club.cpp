#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=100101;
const int inf=1e9+7;
int T,n,b[M],ans,cnt,tmp;
struct node{
	int x[4],mx[4];
	void fid(){
		if(x[1]>=x[2]&&x[2]>=x[3]){
			mx[1]=1;mx[2]=2;mx[3]=3;
		}
		else if(x[1]>=x[3]&&x[3]>=x[2]){
			mx[1]=1;mx[2]=3;mx[3]=2;
		}
		else if(x[2]>=x[1]&&x[1]>=x[3]){
			mx[1]=2;mx[2]=1;mx[3]=3;
		}
		else if(x[2]>=x[3]&&x[3]>=x[1]){
			mx[1]=3;mx[2]=1;mx[3]=2;
		}
		else if(x[3]>=x[1]&&x[1]>=x[2]){
			mx[1]=2;mx[2]=3;mx[3]=1;
		}
		else{
			mx[1]=3;mx[2]=2;mx[3]=1;
		}
	}
}a[M];
int X,Y,Z;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		For(i,1,n){
			For(j,1,3) scanf("%d",&a[i].x[j]);
			a[i].fid();
		}
		ans=0;cnt=0;X=0;Y=0;Z=0;
		For(i,1,n){
			For(j,1,3){
				if(a[i].mx[j]==1){
					if(j==1) X++;
					if(j==2) Y++;
					if(j==3) Z++;
					ans+=a[i].x[j];
				}
			}
		}
		if(X>n/2){//如果进入a工厂的超标了 
			For(i,1,n){
				if(a[i].mx[1]==1){//如果你要去a工厂 
					For(j,1,3) if(a[i].mx[j]==2) tmp=j;//tmp的值是三个中的第二名 
					b[++cnt]=a[i].x[1]-a[i].x[tmp];
				}
			}
			sort(b+1,b+1+cnt);
			For(i,1,X-n/2) ans-=b[i];
		}
		if(Y>n/2){//如果进入a工厂的超标了 
			For(i,1,n){
				if(a[i].mx[2]==1){//如果你要去a工厂 
					For(j,1,3) if(a[i].mx[j]==2) tmp=j;//tmp的值是三个中的第二名 
					b[++cnt]=a[i].x[2]-a[i].x[tmp];
				}
			}
			sort(b+1,b+1+cnt);
			For(i,1,Y-n/2) ans-=b[i];
		}
		if(Z>n/2){//如果进入a工厂的超标了 
			For(i,1,n){
				if(a[i].mx[3]==1){//如果你要去a工厂 
					For(j,1,3) if(a[i].mx[j]==2) tmp=j;//tmp的值是三个中的第二名 
					b[++cnt]=a[i].x[3]-a[i].x[tmp];
				}
			}
			sort(b+1,b+1+cnt);
			For(i,1,Z-n/2) ans-=b[i];
		}
//		For(i,1,n) ++mx[a[i].mx];
//		For(i,1,n) ans+=a[i].mx;
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
