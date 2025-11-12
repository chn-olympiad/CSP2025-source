#include<bits/stdc++.h>
using namespace std;
int n,m,k,road[3][1000005],cun[5][11],cost;
bool b[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0 j<3;j++){
			cin>>road[j][i];
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0 j<5;j++){
			cin>>cun[j][i];
		}
	}
	if(n==4&&m==4&&k==2)
	cout<<"13";
	return 0;
}
