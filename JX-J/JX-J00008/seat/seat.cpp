#include <iostream>
#include <cstring>
using namespace std;

int m,n;
int map[19][19];
int vis[105];
int fenshu=0;
int qiuzhi;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m*n;i++){
        cin>>vis[i];
        if (i==1) qiuzhi = vis[i];
	}
	for (int i=1;i<=m*n;i++){
        for(int j=i+1;j<=m*n;j++){
            if (vis[j]>vis[i]){
                swap(vis[j],vis[i]);
            }
        }
	}
	int i=1,j=1;
	bool k=1;
	int y = 1;
	while(j<=n){
        if (k){
            map[i][j] = vis[y];
            if (i==m){
                j++;
                k=0;
                i--;
            }
            i++;
        }else{
            map[i][j] = vis[y];
            if (i==1){
                j++;
                k=1;
                i++;
            }
            i--;
        }
        y++;
	}
	for (int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (map[i][j]==qiuzhi){
                cout<<j<<" "<<i<<endl;
                break;
            }
        }
	}
	return 0;

}
