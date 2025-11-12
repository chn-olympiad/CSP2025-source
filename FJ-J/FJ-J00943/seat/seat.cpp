#include <bits/stdc++.h>
using namespace std;
int a[10010];
int fx[5]={0,0,0,1,-1};
int fy[5]={0,-1,1,0,0};
bool f[110][110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int t;
	int ans=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	f[1][1]=1;
	while(1){
		for(int i=1;i<=4;i++){
			int dx=x+fx[i];
			int dy=y+fy[i];
			if(dx>=1&&dy>=1&&dx<=n&&dy<=m&&f[dx][dy]==0){
				x=dx;y=dy;
				f[x][y]=1;
				ans++;
				if(a[ans]==t){
					cout<<x<<" "<<y;
					return 0;
				}
				break;
			}
		}
	}
	return 0;
}

