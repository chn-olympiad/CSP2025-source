#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn],v[1000][1000],n,m,k,h;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    k=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    bool cp=1;
    for(int i=1;i<=m;i++){
        if(cp){
            for(int j=1;j<=n;j++){
                h++;
                v[i][j]=a[h];
            }
            cp=0;
        }else{
            for(int j=n;j>=1;j--){
                h++;
                v[i][j]=a[h];
            }
            cp=1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]==k){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
