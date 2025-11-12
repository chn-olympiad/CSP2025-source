#include<iostream>
#include<cmath>
#include<algorithm>
#define N 1001000
using namespace std;
struct R{
	int w,u,v;
	bool operator<(R p){
		if(this->w<p.w){
			return 1;
		}
		return 0;
	}
}r[N*2];
int n,m,k,kwt[10][N/100];
int bl[N/100],trans[N/100],tri;
long long mi=2^63,tm;
void gowork(){
		sort(r,r+n+m);
		for(int i=0;i<n+1;i++){
			bl[i]=-1;
			trans[i]=i;
		}
		for(int i=0;i<m+n;i++){
			if(bl[r[i].v]>=0&&trans[bl[r[i].v]]==trans[bl[r[i].u]]) continue;
			if(bl[r[i].u]<0){
				if(bl[r[i].v]<0){
					bl[r[i].v]=tri;
					bl[r[i].u]=tri++;
				}
				else{
					bl[r[i].u]=trans[bl[r[i].v]];
				}
			}
			else{
				if(bl[r[i].v]<0){
					bl[r[i].v]=trans[bl[r[i].u]];
				}
				else{
					if(trans[bl[r[i].v]]<trans[bl[r[i].u]]){
						trans[bl[r[i].u]]=trans[bl[r[i].v]];
					}
					else trans[bl[r[i].v]]=trans[bl[r[i].u]];
				}
			}
			tm+=r[i].w;
		}
		if(tm<mi) mi=tm;
		return;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int t=0;t<k;t++){
		cin>>mi;
		for(int i=0;i<n;i++){
			cin>>kwt[t][i];
		}
	}
	mi=2^63;
	gowork();
	cout<<mi;
	return 0;
}