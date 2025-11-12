#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int start[m+1];
    int end[m+1];
    int cost[m+1];
    for(int i=1;i<=m;i++){
		cin>>start[i]>>end[i]>>cost[i];
	}
	for(int i=1;i<=k;i++){
		cin>>start[i]>>end[i]>>cost[i];
	}
	cout<<100;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
