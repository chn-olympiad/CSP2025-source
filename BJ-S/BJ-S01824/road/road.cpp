#include<iostream>

using namespace std;

int main(){
    int n, m, k;
    int max_m = 1000005;
    int u[max_m], v[max_m], w[max_m];
    int money = 0;

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }

    for(int i=0;i<m;i++){
        money += w[i];
    }

    cout<<money;

	return 0;
}
