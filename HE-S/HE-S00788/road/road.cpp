#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int city[(int)1e4+10];

struct node{
	int u,v,w;
}a[(int)1e6+10];

bool cmp(node x,node y){
	return x.w>y.w;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	
	cin>>n>>m>>k;
	cout<<m;
	
	return 0;
	
}
