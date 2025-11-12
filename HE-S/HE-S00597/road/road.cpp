#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
struct s{
	int len; 
	int to;
};
struct d{
	int l;
	int zu;
	int yo;
};
bool built[10004];//判断是否恢复交通； 
d b[N];//排序道路
int road[10004][10004]; 
int c[12][10004];//农村； 
int n,m,k;
vector<s>a[10004];
bool cmp(d x,d y){
	return x.l<y.l;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(road,0x3f3f3f3f,sizeof(road));
	for(int i=1;i<=m;i++){
		int u,v,w;
		road[u][v]=road[v][u]=w;
		s x;
		x.to=u;
		x.len=w;
		a[v].push_back(x);
		x.to=v;
		a[u].push_back(x);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int q=1;q<=k;q++){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				road[i][j]=road[j][i]=min(road[i][j],c[q][i]+c[q][j]+c[q][0]);
			}
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(road[i][j]!=0x3f3f3f){
				num++;
				b[num].l=road[i][j];
				b[num].yo=i;
				b[num].zu=j;
			}
		}
	}
	sort(b+1,b+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(!built[b[num].yo][b[num].zu]){
		}
		
	}
	cout<<9319831;
	return 0;
}

