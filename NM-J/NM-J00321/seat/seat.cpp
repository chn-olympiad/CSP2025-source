#include<bits/stdc++.h>
using namespace std;
int n,m,sum,cnt=1;
struct st{
	int d,id,idx;
};
int b[20][20];
st a[110];
bool cmp(st x,st y){
	if(x.d!=y.d) return x.d>y.d;
	return x.id<y.id;	
}
int dir=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i].d;
		a[i].id=i;
	}
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		a[i].idx=i;
		//cout<<a[i].d<<' '<<a[i].id<<' '<<a[i].idx<<endl;
	}
	if(a[sum].id==1){
		cout<<m<<' '<<n;
		return 0;
	}
	if(m%2==1){
		b[n][m]=a[sum].id;
	}
	else{
		b[1][m]=a[sum].id;
	}
	int x=1,y=1;
	while(cnt<sum){
		b[x][y]=a[cnt].id;
		if(b[x][y]==1){
			cout<<y<<' '<<x;
			return 0;
		}
		if(cnt==sum) break;
		if(dir==1){
			int tx=x+1;
			if(tx<=n&&b[tx][y]==0){
				x++;
				cnt++;
			}
			else{
				dir=2;
				//y++;
			}
		}
		else if(dir==2){
			int ty=y+1;
			if(ty<=m&&b[x][ty]==0){
				y++;
				dir=3;
				cnt++;
				//x--;
			}
		}
		else if(dir==3){
			int tx=x-1;
			if(tx>=1&&b[tx][y]==0){
				x--;
				cnt++;
			}
			else{
				dir=4;
			}
		}
		else if(dir==4){
			int ty=y+1;
			if(ty<=m&&b[x][ty]==0){
				y++;
				dir=1;
				cnt++;
				//x++;
			}
		}
		
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<b[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
		*/
	}
	return 0;
}
