#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct num{
	int x,y,z,id;
}a[MAXN];
int t,n;
int ans;
int sumx,sumy,sumz;
num t1[MAXN],t2[MAXN];
bool vis[MAXN];
bool cmp(num x,num y){
	return x.x<y.x;
}
bool cmp2(num x,num y){
	return (x.x-x.y)<(y.x-y.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		sumx=sumy=sumz=0;
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			sumx+=a[i].x;
			sumy+=a[i].y;
			sumz+=a[i].z;
		}
		int pos;
		if(sumx>sumy&&sumx>sumz){
			ans=sumx;
			for(int i=1;i<=n;i++){
				t1[i].x=a[i].x-a[i].y;
				t2[i].x=a[i].y-a[i].z;
				t1[i].id=t2[i].id=i;
//				cout<<t1[i].x<<" "<<t2[i].x<<endl;
			}
		}
		if(sumy>sumx&&sumy>sumz){
			ans=sumy;
			for(int i=1;i<=n;i++){
				t1[i].x=a[i].y-a[i].z;
				t2[i].x=a[i].z-a[i].x;
				t1[i].id=t2[i].id=i;
			}
		}
		if(sumz>sumy&&sumz>sumx){
			ans=sumz;
			for(int i=1;i<=n;i++){
				t1[i].x=a[i].z-a[i].y;
				t2[i].x=a[i].y-a[i].x;
				t1[i].id=t2[i].id=i;
			}
		}
		sort(t1+1,t1+n+1,cmp);
		sort(t2+1,t2+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans-=t1[i].x;
			vis[t1[i].id]=1;
		}
		for(int i=1;i<=n/2;i++){
			if(vis[t2[i].id]&&t2[i].x<0){
				ans-=t2[i].x;
			}
		}
		cout<<ans<<endl;
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

1
2
10 9 8
4 0 0
*/
