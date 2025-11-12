#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int n,m,a,num;
bool found=0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    num=n*m;
    int x[num+1];
    x[0]=-1;
    for(int i=1; i<=num; i++){
        cin>>x[i];
    }
    a=x[1];
    sort(x,x+num+2,cmp);
    for(int j=1; j<=m; j++){
        if(j%2==1){
            for(int i=1; i<=n; i++){
                if(x[(j-1)*n+i]==a){
                    found=1;
                    cout<<j<<' '<<i;
                    break;
                }
            }
        }
        else{
            for(int i=n; i>=1; i--){
                if(x[j*n-i+1]==a){
                    found=1;
                    cout<<j<<' '<<i;
                    break;
                }
            }
        }
        if(found){
            break;
        }
    }
    return 0;
}
