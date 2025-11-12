#include<bits/stdc++.h>
using namespace std;
int b[15][15];
struct node{
	int id,score;
}a[105];
bool cmp(node A,node B){
	return A.score>B.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	if(n==1){
		for(int i=1;i<=n*m;i++){
			if(a[i].id==1){
				cout<<i<<' '<<1<<'\n';
				return 0;
			}
		}
	}
	int x=1,y=1,cnt=1;
	bool f=0;
	while(cnt<=n*m){
		b[x][y]=a[cnt].id;
		cnt++;
		if((x==n||x==1)&&(cnt!=2)){
			y++;
			b[x][y]=a[cnt].id;
			cnt++;
			f=!f;
			if(!f)x++;
			else x--;
		}else{
			if(!f)x++;
			else x--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		    if(b[i][j]==1){
				cout<<j<<' '<<i<<'\n';
				return 0;
			}	
			//cout<<b[i][j]<<' ';
		}
		//cout<<endl;
	}
	return 0;
}
//1 2 12
