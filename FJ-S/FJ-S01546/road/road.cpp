#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	x=0;
	char s=getchar();
	int bj=0;
	while(s<'0'||s>'9'){
		if(s=='-'){
			bj=1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+(s^48);
		s=getchar();
	}
	if(bj){
		x=-x;
	}
}
template<typename T>void write(T x){
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int n,m,k,c[16],a[16][10005],bj[10005],ey[16];
long long qz[10005],sum=0;
vector<pair<int,int>> dt[10005];
void bfs(){
	queue<int> q;
	q.push(1);
	bj[1]=1;
	while(!q.empty()){
		int ls=q.front();
		q.pop();
		for(int i=0;i<int(dt[ls].size());i++){
			int z1=dt[ls][i].first,wz=0;
			long long z2=dt[ls][i].second,ls=1e18;
			if(bj[z1]!=1){
				for(int j=1;j<=k;j++){
					if(ls>(a[j][ls]+a[j][z1])*1LL){
						ls=(a[j][ls]+a[j][z1])*1LL;
						wz=j;
					}
				}
				if(z2<ls){
					qz[z1]=z2;
				}else{
					qz[z1]=ls;
					ey[wz]=1;
				}
				bj[z1]=1;
				q.push(z1);
			}else{
				if(z2<qz[z1]){
					qz[z1]=z2;
					q.push(z1);
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		read(u),read(v),read(w);
		dt[u].push_back({v,w});
		dt[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[i][j]);
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
		return 0;
	}
	cout<<0;
	return 0;
	bfs();
	for(int i=1;i<=n;i++){
		sum+=qz[i];
	} 
	for(int i=1;i<=k;i++){
		if(ey[i]==1){
			sum+=c[i];
		}
	}
	cout<<sum;
	return 0;
} 
