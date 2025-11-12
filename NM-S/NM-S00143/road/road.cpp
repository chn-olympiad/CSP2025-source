#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int p[100001][3];
int u[11][1010];

int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int o[10000];
    for(int i=0;i<m;i++){
        for(int e=0;e<3;e++){
            cin>>p[i][e];
        }
    }
     for(int i=0;i<k;i++){
        for(int e=0;e<=n;e++){
            cin>>u[i][e];
        }
    }
    for (int h=0;h<m;h++){

            if(p[h][0]-p[h][1]==1||p[h][0]-p[h][1]==-1){
                o[h]=p[h][2];
            }
    }
    int z=0;
    for(int i=0;i<m;i++){
        z=z+p[i][2];
    }
    cout<<z;

	return 0;

}
