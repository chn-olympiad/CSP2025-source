#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,c[33+N],country[N+33][N+33];
ll ans;
int fa[M],size[M];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	int x=find(a),y=find(b);
	if(size[x]>size[y]){
		size[x]+=size[y];
		fa[y]=fa[x];
	}
	else{
		size[y]+=size[x];
		fa[x]=fa[y];
	}
}
struct city{
	int u,v,w;
}a[M+N*10];
vector<int>edge;
bool cmp(city aa,city bb){
	return aa.w<bb.w;
}
ll kruskal(){
	ll sum=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			merge(a[i].u,a[i].v);
			sum+=a[i].w;
			edge.push_back(i);
		} 
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		fa[i]=i,size[i]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i+n];
		for(int j=1;j<=n;j++){
			int price;
			cin>>price;
			country[i+n][j]=country[j][i+1]=price;
		}
	}
	sort(a+1,a+1+m,cmp);
	ans=kruskal();
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=edge.size()-1;i>=0;i--){
		for(int j=n+1;j<=n+k;j++){
			if(c[j]+country[j][a[edge[i]].u]+country[j][a[edge[i]].v]<a[edge[i]].w){
				ans-=a[edge[i]].w;
				ans+=c[j]+country[j][a[edge[i]].u]+country[j][a[edge[i]].v];
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
Now is 18:19,there is just 6 minutes left
But I found my thought was wrong
Oh ****!
This way,maybe I won't win the first prize
All right,I know I am weak in OI
Although I am a 8th grader,but this is the first time I join in CSP-S
I can just get 96 points
I am too vegetable(sad
****!
I love Kaedehara Kazuha and Furina and Zhongli and Arlechino!
Kaedehara__Kazuha is my luogu name
*/
