#include <bits/stdc++.h>
using namespace std;
int n,m,k;

struct lj{
	int city1;
	int city2;
	int jiage;
}road[100005];
int city[10000];
int jin;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>road[i].city1>>road[i].city2>>road[i].jiage;
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(road[i].jiage>road[i+1].jiage){
				int a,b,c;
				a=road[i].jiage;
				b=road[i].city1;
				c=road[i].city2;
				road[i].jiage=road[i+1].jiage;
				road[i].city1=road[i+1].city1;
				road[i].city2=road[i+1].city2;
				road[i+1].jiage=a;
				road[i+1].city1=b;
				road[i+1].city2=c;
			}
		}
	}
	
		
	for(int i=0;i<n;i++){
		if(city[road[i].city1]<2 and city[road[i].city2]<2){
			city[road[i].city1]++;
			city[road[i].city2]++;
			jin=jin+road[i].jiage;
		}	
	}
	cout<<jin;
	return 0;
}
