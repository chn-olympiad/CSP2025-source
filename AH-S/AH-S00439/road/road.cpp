#include<bits/stdc++.h>
using namespace std;
long long road[1000005][5];
long long village[25][10005];
long long city[10005];
long long price[20];
long long n,m,k,ans=0;
bool boo(){
	memset(city,0,sizeof(city));
	for(int i=1;i<=n;i++){
		city[road[i][1]]++;
		city[road[i][2]]++;
	}
	for(int i=1;i<=m;i++){
		if(city[i]==0){
			return false;
		}
	}
	for(int i=1;i<=m;i++){
		if(city[i]>=2){
			return true;
		}
	}
	return false;
}
long long minn(int i){
	long long minnn=INT_MAX;
	for(int j=1;j<=m;j++){
		minnn=min(minnn,village[i][j]);
	}
	return minnn;
}
/*int findmin(int k){
	int m=INT_MAX;
	for(int i=1;i<=k;i++){
		m=min(m,price[i]);
	}
	return m;
}
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i][1]>>road[i][2]>>road[i][3];
		ans+=road[i][3];
	}
	for(int i=1;i<=k;i++){
		cin>>village[i][1];
		for(int j=2;j<=n+1;j++){
			cin>>village[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		long long v,w;  // v=left,w=right
		v=road[i][1];
		w=road[i][2];
		road[i][1]=0;
		road[i][2]=0;
		if(boo()){
			ans-=road[i][3];
		}
		else{
			road[i][1]=v;
			road[i][2]=w;
		}
	}
		cout<<ans<<endl;
	/*
	ans=0;
	for(int i=1;i<=n;i++){
		memset(price,0,sizeof(price));
		if(road[i][1]==0) continue;
		long long left=road[i][1],right=road[i][2];
		road[i][1]=0;
		if(boo){
			for(int j=1;j<=k;j++){
				price[j]=village[j][road[i][2]]+minn(j);
			}
			ans+=min(road[i][3],findmin(k));
		}
		road[i][1]=left;
		road[i][2]=0;
		else if(boo){
			for(int j=1;j<=k;j++){
				price[j]=village[j][road[i][1]]+minn(j);
			}
			ans+=min(road[i][3],findmin(k));
		}
		road[i][2]=right;
		else{
			for(int j=1;j<=k;j++){
				price[j]=village[j][road[i][1]]+village[j][road[i][2]];
			}
			ans+=min(road[i][3],findmin(k));
		}
	}
	cout<<ans<<endl;
	*/
	if(k!=0){
		cout<<0<;
	}
	return 0;
}
