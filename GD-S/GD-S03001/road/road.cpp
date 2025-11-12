#include<bits/stdc++.h>
#define int long long
using namespace std;
struct f{
	int x,y,z,e;
}r[10000005];
int cmp(f a,f b){
	return a.z<b.z;
}
int ci[10005],dw[10015][10015];
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	int l=0,ans=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >>a>>b>>c;
		r[++l].x=a;
		r[l].y=b;
		r[l].z=c;
	} 
	for(int i=1;i<=k;i++){
		int a;
		cin >>a;
		for(int j=1;j<=n;j++){
			int b;
			cin >>b;
			r[++l].x=n+i;
			r[l].y=j;
			r[l].e=a;
			r[l].z=a+b;
		//	cout <<a<<" "<<b<<" "<<r[l].z<<endl;
		}
	}
	sort(r+1,r+1+m+k*n,cmp);
	for(int i=1;i<=m+k*n;i++){
		//cout <<r[i].x<<" "<<r[i].y<<" "<<r[i].z<<endl;
		if(dw[r[i].x][r[i].y]==1)continue;
		if(r[i].x<=n&&r[i].y>n&&ci[r[i].x]==1&&ci[r[i].y]==0)continue;
		if(r[i].y<=n&&r[i].x>n&&ci[r[i].y]==1&&ci[r[i].x]==0)continue;
		if(ci[r[i].x]==0&&r[i].x<=n){
			ci[r[i].x]=1;
			for(int j=1;j<=n+k;j++){
				if(ci[j]==1&&dw[j][r[i].y]==1){
					dw[j][r[i].x]=1;
					dw[r[i].x][j]=1;
				}
			}
		}
		if(ci[r[i].y]==0&&r[i].y<=n){
			ci[r[i].y]=1;
			for(int j=1;j<=n+k;j++){
				if(ci[j]==1&&dw[j][r[i].x]==1){
					dw[j][r[i].y]=1;
					dw[r[i].y][j]=1;
				}
			}
		}
		int flag=0;
		for(int j=1;j<=n+k;j++){
			if(dw[j][r[i].x]==1&&r[i].x>n||dw[j][r[i].y]==1&&r[i].y>n){
				flag=1;
			}
		}
		if(flag==1)ans-=r[i].e;
		ans+=r[i].z;
		dw[r[i].x][r[i].y]=1;
		dw[r[i].y][r[i].x]=1;
	//	cout <<i<<" "<<ans<<endl;
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout <<dw[i][j]<<" ";
		}
		cout <<endl;
	}
	*/
	cout <<ans<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
