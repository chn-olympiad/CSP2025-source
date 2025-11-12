#include<bits/stdc++.h>
#define int long long
#define MAXN 2147483648 
using namespace std;
int n,m,k;
vector<int> farm;
vector<vector<int> > farmroad;
vector<int> visited;
struct prim{
	int bian;
	int dian1;
	int dian2;
	
}; 
vector<prim> toall;
vector<prim> shu;

void push(prim needpush){
	shu.push_back(needpush);
	int id=shu.size();
	
	while(needpush.bian<shu[(int)((id-1)/2)].bian){
		
		prim temp=needpush;	 
		shu[id]=shu[(int)((id-1)/2)];
		shu[(int)((id-1)/2)]=temp;
		id=(int)(id-1)/2;
	}
	
	return;	
}
void pop(){
	prim needpop=shu[0];
	shu[0]=shu[shu.resize()];
	prim needpop=shu[0];
	int id=0;
	
	while(2*id+1<=shu.size()){
		int p;
		if(2*id+1<=2*id+2)
		   p=1
		else
		   p=2
		prim temp=needpop;	 
		shu[id]=shu[2*id+p];
		shu[2*id+p]=temp;
		id=2*id+p;
		
	}
	
	return;	
}


  
void read(){
	cin>>n,m,k;
	farm.resize(k);
	farmroad.resize(k,vector<int>(n));
	
	for(int i=0;i<m;i++){
		prim one;
		
		cin>>one.dian1;cin>>one.dian2;cin>>one.bian;
		toall.push_back(one);		
	}
	
	for(int i=0;i<k;i++){
	    cin>>farm[i];
	    
		for(int j=0;j<n;j++)
		    cin>>farmroad[i][j];
}
	return;
}

void add(){
	
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	for(prim which:shu)
	    push(which)
		
	prim frist=shu[0];
	visited[frist.dian1]=1;visited[frist.dian2]=1;
	
	int number=2;
	int current[];
	while(number=!n){
		prim qu=shu[0];
		if(qu.dian1=!visited)
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	return 0;
}
