#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;;
    int a[n][m],b[n*m];
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    int q=b[0],x=0,y=0;
    sort(b,b+(n*m),cmp);
    for(int i=0;i<n*m;i++){
        a[x][y]=b[i];
        if(b[i]==q){
            cout<<x+1<<" "<<y+1;
            break;
        }
        if(x%2==0){
            if(y==n-1){
                x++;
            }
            else{
                y++;
            }
        }
        else{
            if(y==0){
                x++;
            }
            else{
                y--;
            }
        }
    }
    return 0;
}

