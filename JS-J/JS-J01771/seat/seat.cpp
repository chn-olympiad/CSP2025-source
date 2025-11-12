#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
    if(x!=y)return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int w=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==w){
            w=i;
            break;
        }
    }
    for(int j=1;j<=m;j++){
        int g;
        if(j%2==1)g=1;
        else g=n;
        for(int i=1;i<=n;i++){
            if((j-1)*n+i==w){
                cout<<j<<" "<<g<<endl;
                break;
            }
            if(j%2==1)g++;
            else g--;
        }
    }
    return 0;
}
