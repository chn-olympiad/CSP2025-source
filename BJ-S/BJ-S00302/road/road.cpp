#include <bits/stdc++.h>
#define int long long
//#define foradd(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
//#define forsub(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;

int n,m,k,a[1000][1000],ccc=0,d[1000];
signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		int x,y,z,flag1=0;
		cin >> x >> y >> z;
		for (int i=1;i<=n;i++){
			if (a[i][y]!=0){
				flag1=1;
			}
		}
		if (flag1==1){
			continue;
		}else{
			a[x][y]+=z;
		}
	}
	int p,q;
	for (int i=1;i<=k;i++){
		cin >> p;
		int ttt=0,bbb=0;
		for (int j=1;j<=n;j++){
			cin >> q;
			a[p][q]=min(a[p][q],q);
			if (a[p][q]<q){
				ttt+=a[p][q]-q;
				ccc++;
				bbb++;
				d[i]=q;
			}
		}	
		if (ttt<p){
			ccc-=bbb;
			//memset(d+ccc,0,sizeof(d));			
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ans+=a[i][j];
		}
	}
	for (int i=1;i<=ccc;i++){
		ans+=d[i];
	}
	cout << ans;
	return 0;
}


