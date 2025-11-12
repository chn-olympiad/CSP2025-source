#include<bits/stdc++.h>
using namespace std;
struct st{
	long l;
	long r;
	long cost;
};
int find(int id,int idi[100005]){
	if(idi[id]==id){
		
		return -1;
	}
	int t=find(id,idi-1);
	idi[id]=t;
	return t;
}
void hb(int idi[100005],st p){
	long l=find(p.l,idi);
	long r=find(p.r,idi);
	if(l!=r){
		idi[r]=idi[l];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	st ro={};
	int idi[100005]={};
	long long m(0),n(0),k(0);
	scanf("%d%d%d",&m,&n,&k);
	for(long i=0;i<n;i++){
		st p={};
		cin>>p.l>>p.r>>p.cost;
		ro=p;
		hb(idi,ro);
	}
	vector<int> cx(n+1);
	vector<int> yy(n+1);
	for(int i=0;i<n;i++){
		long pay(0);
		scanf("%d",&pay);
		cx[i]=pay;
	}
	for(int i=0;i<n;i++){
		long pay(0);
		scanf("%d",&pay);
		yy[i]=pay;
	}
	
	return 0;
}
