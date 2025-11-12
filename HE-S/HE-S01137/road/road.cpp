#include<bits/stdc++.h>
using namespace std;
struct S{
	int city1,city2,money;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	vector<S> a(m+5);
	int maxx=0;
	for(int i=1;i<=m;i++){
		cin>>a[i].city1>>a[i].city2>>a[i].money;
	}
	int new1[15];
	vector<int> neww[15];
	for(int i=1;i<=k;i++){
		cin>>new1[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			neww[i].push_back(x);
		}
		if(neww[i].size()>=maxx){
			maxx=neww[i].size()+5;
		}
	}
	long long sum=0,f[15]={0};
	int vis[m+5]={0},nvis[15][maxx]={0};
	for(int i=1;i<=n;i++){
		int minn=0x3f3f3f,xx=0;
		for(int j=1;j<=m;j++){
			if(a[j].city1==i||a[j].city2==i){
				if(a[j].money<=minn&&vis[j]==0){
					minn=a[j].money;
					xx=j;
				}
			}
		}
		int yy=0,yyy=0;
		for(int j=1;j<=k;j++){
			if(f[j]==0){
				if(minn>=new1[j]+neww[j][i-1]&&nvis[j][i-1]==0){
					f[j]=1;
					minn=new1[j]+neww[j][i-1];
					yy=j;
					yyy=i-1;
				}
			}
			else{
				if(minn>>neww[j][i-1]&&nvis[j][i-1]==0){
					minn=neww[j][i-1];
					yy=j;
					yyy=i-1;
				}
			}
		}
		if(yy!=0&&yyy!=0){
			nvis[yy][yyy]=1;
		}
		else{
			vis[xx]=1;
		}
		sum+=minn;
	}
	cout<<sum;
	return 0;
}
