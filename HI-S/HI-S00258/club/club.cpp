#include<bits/stdc++.h> 

using namespace std;

int t,n,max1;
struct p{
	int q=0;
	int ma;
	int mb;
	int mc;
}worker[100005]; 

void dfs(int x,int a,int ar,int b,int br,int c,int cr){
	if(x==n){
		max1=max(max1,(a+b+c));
		return;
	}
	if(ar<n/2) dfs(x+1,a+worker[x].ma,ar+1,b,br,c,cr); 
	if(br<n/2) dfs(x+1,a,ar,b+worker[x].mb,br+1,c,cr); 
	if(cr<n/2) dfs(x+1,a,ar,b,br,c+worker[x].mc,cr+1); 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		max1=0;
		for(int i=0;i<n;i++) cin>>worker[i].ma>>worker[i].mb>>worker[i].mc;
		dfs(0,0,0,0,0,0,0);
		cout<<max1;
	} 
	return 0;
}
