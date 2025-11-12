#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long
int T,n,ans,c[4];
struct node{
	int x,id;
}a[N][4];
struct node2{
	int id1,id2,x1,x2;
}b[N];
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node2 a,node2 b){
	return a.x1-a.x2>b.x1-b.x2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	int i,j;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++)cin>>a[i][j].x,a[i][j].id=j;
			sort(a[i]+1,a[i]+1+3,cmp1);
			b[i].x1=a[i][1].x,b[i].x2=a[i][2].x;
			b[i].id1=a[i][1].id,b[i].id2=a[i][2].id;
		}
		sort(b+1,b+1+n,cmp2);
		ans=c[1]=c[2]=c[3]=0;
		for(i=1;i<=n;i++){
			int x=b[i].id1,y=b[i].id2;
			if(c[x]>=n/2){
				ans+=b[i].x2;
				c[y]++;
			}else c[x]++,ans+=b[i].x1;
		}
		cout<<ans<<"\n";
	}
	return 0;
} /*
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
