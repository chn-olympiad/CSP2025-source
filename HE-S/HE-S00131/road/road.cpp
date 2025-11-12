#include<bits/stdc++.h>
using namespace std;
long long man=100005,ans=0;
struct er{
	long long a,b;
	long long c;
};
int n,m,k,t;
er a[1000000+5];
long long w[10][10000+5];
int r[10000+5];
void dfs(long long y,long long u,long long z){
	if(z>=k){
		return;
	}
	if(y>=n){
		return ;
	}
	if(u>=m){
		return;
	}
	int h;
	for(int i=0;i<n;i++){
		if(r[i]>0){
			h++;
		}
	}
	if(t>=z&&h==n&&ans<man){
		man=ans;
		return;
	}
	ans+=w[z][0];
	ans+=w[z][y];
	t++;
	r[y-1]++;
	dfs(y+1,u,z+1);
	ans-=w[z][0];
	ans-=w[z][y];
	t--;
	r[y-1]--;
	ans+=a[u].c;
	r[a[u].a-1]++;
	r[a[u].b-1]++;
	dfs(y,u+1,k);
	r[a[u].a-1]--;
	r[a[u].b-1]--;
	return ;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>w[i][j];
		}
	}
	for(int i=0;i<n;i++){
		r[i]=0;
	}
	dfs(0,0,0);
	cout<<man<<endl;
	return 0;
}
