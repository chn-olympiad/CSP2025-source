#include<bits/stdc++.h>
using namespace std;
int sor[200],n,m,xr,x=1,y=1,a[20][20],rcnt=1,cnt,j=0;
bool dao;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sor[i];
    }
    xr=sor[1];
    sort(sor+1,sor+n*m+1,cmp);
    for(int i=0;i<n;i++){
        rcnt++;
        if(sor[i]==xr){
            break;
        }
    }
    for(int i=1;i<=m;i++){
        while(i%2==1&&j<n){
            j++;
            cnt++;
            if(cnt==rcnt){
                cout<<i<<" "<<j;
                return 0;
            }
        }
        while(i%2==0&&j>=1){
            j--;
            cnt++;
            if(cnt==rcnt){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}

