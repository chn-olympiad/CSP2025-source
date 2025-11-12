#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[12][12];
int score[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<(n*m);i++)cin>>score[i];
	
	int my=score[0];
	sort(score,score+n*m+1,cmp);
	
	int tot=-1;
	for(int x=1;x<=m;x++){
		if(x%2==0){
			for(int y=n;y>=1;y--){
				tot++;
				a[x][y]=score[tot];
			}
		}else{
			for(int y=1;y<=n;y++){
				tot++;
				a[x][y]=score[tot];
			}
		}
	}
	//out
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==my){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}