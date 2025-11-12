#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m,a[N],pos=0,b[N][N];
bool cmp(int a,int b){
	return a>b;
} 
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int xs=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xs){
			pos=i;
			break;
		}
	}
	int tot=0;
	for(int i=1;i<=m;i++){
		if(i%2==1) for(int j=1;j<=n;j++) b[j][i]=++tot;
		else for(int j=n;j>=1;j--) b[j][i]=++tot;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==pos){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
