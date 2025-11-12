#include<bits/stdc++.h>
using namespace std;
int n,m,a,u;
int f[110];
int z[11][11];
int main(){
    freopen("seat.in","r",stdin);//666 cha dian bu hui xie
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
    f[0]=a;
	for(int i=1;i<(n*m);i++){
        cin>>u;
        f[i]=u;
	}
	sort(f,f+(n*m));
	for(int i=0;i<=n;i++) z[i][0]=114514;
    for(int i=0;i<=m;i++) z[0][i]=114514;
    bool flag=1;
    int s=0;
	for(int i=1;i<=m;i++){
        if(flag){
            for(int j=1;j<=n;j++){
                z[j][i]=f[s];
                s++;
            }
        }else{
            for(int j=n;j>=1;j--){
                z[j][i]=f[s];
                s++;
            }
        }
        flag=(!flag);
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(z[i][j]==a){
                cout<<i<<' '<<j;
                return 0;
            }
        }
	}
	return 0;
}
