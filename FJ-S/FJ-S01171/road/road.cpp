#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int num=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=((num<<3)+(num<<1))+ch-48; 
		ch=getchar();
	}
	return num;
}
int n,m,k;
struct act{
	int x;
	int w;
};
struct bct{
	int x;
	int y;
	int w;
};
bool operator < (const bct &a,const bct &b){
	return a.w>b.w;
}
vector<act> v1[10015];
vector<act> v[10015];
int c[10015];
int a[15][10015];
int cnt;
int ans;
int fa[10015];
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
int prim(){
	for(int i = 1;i<=cnt;i++){
		fa[i]=i;
	}
	priority_queue<bct> q;
	for(int i = 1;i<=cnt;i++){
		for(int j = 0;j<v1[i].size();j++){
			q.push({i,v1[i][j].x,v1[i][j].w});
		}
	}
	int num=0;
	while(!q.empty()){
		bct temp=q.top();
		q.pop();
		if(find(temp.x)==find(temp.y)){
			continue;
		}
		fa[temp.x]=temp.y;
		num+=temp.w;
	}
	return num;
}
vector<int> arr;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i = 1;i<=m;i++){
		int x=read(),y=read(),z=read();
		v[x].push_back((act){y,z});
		v[y].push_back((act){x,z});
	}
	for(int i = 1;i<=k;i++){
		c[i]=read();
		for(int j = 1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int j = 1;j<=n+k;j++){
		v1[j]=v[j];
	}
	cnt=n;
	int temp=prim();
	for(int i = 1;i<=k;i++){
		cnt=n+1;
		for(int j = 1;j<=n;j++){
			v1[cnt].push_back({j,a[i][j]});
			v1[j].push_back({cnt,a[i][j]});
		}
		if(c[i]+prim()<=temp){
			arr.push_back(i);
		}
		for(int j = 1;j<=n+k;j++){
			v1[j]=v[j];
		}
	}
	cnt=n;
	for(int sd = 0;sd<arr.size();sd++){
		int i = arr[sd];
		cnt++;
		ans+=c[i];
		for(int j = 1;j<=n;j++){
			v1[cnt].push_back({j,a[i][j]});
			v1[j].push_back({cnt,a[i][j]});
		}
	}
	cout<<ans+prim();
	return 0;
}
