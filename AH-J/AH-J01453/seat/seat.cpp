#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[150];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int r=a[0];
    sort(a,a+n*m,cmp);
    int b[15][15],cnt=-1;
    bool flag=0;
    for(int i=0;i<n;i++){
        if(flag==1){
            for(int j=m-1;j>=0;j--){
                cnt++;
                b[j][i]=a[cnt];
            }
        }else{
            for(int j=0;j<m;j++){
                cnt++;
                b[j][i]=a[cnt];
            }
        }
        flag=!flag;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]==r){
                cout<<j+1<<" "<<i+1;
                break;
            }
        }
    }
    return 0;
}

