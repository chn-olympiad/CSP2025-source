#include<bits\stdc++.h>
using namespace std;
int k;
int m;
int n;
int h;
int f;
int fa;
int c[10000000];
int z[10000000];
int q[10000000];
int w[10000000];
int a[100000][10000];
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int main(){
cin >> m  >>  n >> k;
for(int i=0;i<n;i++){
    cin>>c[i]>>q[i]>>w[i];
}
for(int i=0;i<k;i++){
    cin>>z[i];
    for(int y=0;y<m;i++){
        cin<<a[i][y];
    }
}
for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
        for(int g=0;g<n;n++){
            if(q[g]=i && w[g]=j){
                f=c[g];
            }
        }
        for(int l=0;l<k;l++){
            fa=a[k][i]+a[k][j]+z[k];
        }
        if(f>fa){
        h=fa+h;
        }
        else{
            h=f+h;
        }
    }
}
cout<<h;
return 0;
}
