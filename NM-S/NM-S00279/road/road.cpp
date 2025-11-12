#include <iostream>
using namespace std;
int find(vector<int>&f,id){
	if(f[id]=id){
		return id;
	}
	f[id]=find(f,f[id]);
	return f[id];
}
int fun(vector<int>& f,int l,int r){
	int x=find(f,l);
	int y=find(f,r);
	if(x!=y){
		f[x]=y;
	}
	
}
int main(){
	freopen("road.in","i",stdin);
	freopen("road.out","o",stdout);
	int n=0,m=0,k=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int l=0,r=0,qi=0;
		cin>>l>>r>>qi;
		
	}
	for(int i=0;i<m;i++){
		int l=0,r=0,qi=0;
		cin>>l>>r>>qi;
		
	}
	
	
	
	
	
	return 0;
}
