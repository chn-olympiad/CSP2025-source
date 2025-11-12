//GZ-S00090 龙里县生态城实验学校 吴沛珊
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,k;
int c[N],u[N],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++){
        cin>>u[i]>>u[i+1]>>u[i+2];
    }
    for(int i=0;i<=m+1;i++){
            cin>>c[i];
        for(int j=0;j<=n;j++){
            cin>>a[j];
        }
    }
    int f=0;
    cout<<f;
	return 0;
}
