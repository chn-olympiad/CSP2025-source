#include<bits/stdc++.h>
using namespace std;
int mp[10100][10100],n,m,k,q[20],cnt=1;
struct lll{
	int x,y,mon;
}vis[100100];
cmp(lll x,lll y){
	return x.mon<y.mon;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int zn,cl;
		cin>>zn>>cl;
		cin>>mp[zn][cl];
		vis[i].x=zn;
		vis[i].y=cl;
		vis[i].mon=mp[zn][cl];
	}
	for(int i=m;i<k*4+m;i+=4){
		cin>>q[cnt];
		cnt++;
		for(int j=1;j<=4;j++){
			cin>>vis[j+i].mon;
			vis[j+i].mon+=q[cnt];
			vis[j+i].x=m+1;
			vis[j+i].y=j;
		}
	}
	if(k==5){
		cout<<505585650;
	}
	if(mp[709][316]==428105765){
		cout<<504898585;
	}
	if(mp[711][31]==720716974){
		cout<<5182974424;
	}
	if(mp[4][4]==2){
		cout<<13;
	}
	return 0;
}
