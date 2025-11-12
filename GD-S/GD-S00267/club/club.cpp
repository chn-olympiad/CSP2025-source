#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct A{
	int x[10];
}peo[100010];
int now[100010];
bool bo[100010][10];
int cnt[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout) ;
	scanf("%d",&t);
	while (t--){
		memset(bo,0,sizeof(bo));
		int tot=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (a>=b&&a>=c){
				tot+=a;
				cnt[1]++;
				now[i]=1;
				bo[i][1]=1;
			}
			else if (b>=a&&b>=c){
				cnt[2]++;
				tot+=b;
				now[i]=2;
				bo[i][2]=1;
			}
			else{
				cnt[3]++;
				tot+=c;
				now[i]=3;
				bo[i][3]=1;
			}
			peo[i].x [1]=a;
			peo[i].x [2]=b;
			peo[i].x [3]=c;
	}
	while (cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
		int minn=-0x3f3f3f,w,to;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				if (bo[i][j])	continue;
				if (peo[i].x [j]-peo[i].x [now[i]]>minn){
					minn=peo[i].x [j]-peo[i].x [now[i]];
					w=i;
					to=j;
				}
			}
		}
		tot+=minn;
		cnt[to]++;
		cnt[now[w]]--;
		now[w]=to;
		bo[w][to]=1;
	}
	cout<<tot<<endl;
	}
	return 0;
}
