#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100005];
int c[105][105];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int idx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++idx];
			c[i][j]=a[idx];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int nowx=1,nowy=1,now=1;
	while(now<=n*m){
		if(a[now]==c[1][1]){
			cout<<nowx<<" "<<nowy;
			return 0;
		}
		if(nowx%2){
			if(nowy<n){
				nowy++;
			}else{
				nowx++;
			}
		}else{
			if(nowy>1){
				nowy--;
			}else{
				nowx++;
			}
		}
		now++;
	}
	return 0;
}

