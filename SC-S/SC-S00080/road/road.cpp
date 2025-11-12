#include<bits/stdc++.h>
using namespace std;
int a[1000000];
vector<int> b[10001];
vector<int> c;
vector<int> f;
int chu = 1;
bool e[10001];
 
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	int k ,n ,m ,i;
	scanf("%d%d%d\n",&n,&m,&k);
	if(k!=0){return 0;}
	void road();
	return 0;
}
void road(int &n,int &m,int &k){
	int u,v,w;
	for(int i=0;i>=m;i++){
	scanf("%d%d%d",&u,&v,&m);
	b[u].push_back(v);
	b[v].push_back(u);
	c.push_back(m);
	}
	#bfs
	
	return;	
}
