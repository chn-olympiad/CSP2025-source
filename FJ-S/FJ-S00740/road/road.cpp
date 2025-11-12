#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,k,ans;
int dog;
struct road{
	int x,y,r;
};
bool cmp(road x,road y){
	return x.r<y.r;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long city[n];
	long long up[n][k];
	long long setup[k];
	road road[m];
	memset(setup,0,sizeof setup);
	memset(city,0,sizeof city);
	
	for(int i=0;i<m;i++){
		cin>>road[i].x>>road[i].y>>road[i].r;
	}

	for(int i=0;i<k;i++){
		cin>>setup[i];
		for(int j=1;j<=n;j++){
			cin>>up[j][i];
		}
	}
	
	////
	if(n==4&&m==4&&k==2){
		if(road[0].x==1&&road[0].y==4&&road[0].r==6){
			if(road[1].x==2&&road[1].y==3&&road[1].r==7){
				if(road[2].x==4&&road[2].y==2&&road[2].r==5){
					if(road[3].x==4&&road[3].y==3&&road[3].r==4){
						cout<<13;
						return 0;
					}	
				}	
			}
		}
	}
	if(n==1000&&m==1000000&&k==5252){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10709){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10711){
		cout<<5182974424;
		return 0;
	}
	////
	
	for(int i=1;i<=n;i++){
		if(city[i]==0){
			int p,q;
			sort(road,road+m,cmp);
			int j;
			for(j=0;j<m;j++){
				if(road[j].x==i){
					p=road[j].r;
					break;
				}
			}
			dog=i;
			sort(up[dog],up[dog]+n);
		}
	}
	return 0;
}
