#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[110],x=2,y=1,rid;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    int lon=n*m;
    sort(a+1,a+lon+1,cmp);

    int opr=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            rid=i;

            break;
        }
    }

    //xiao r de ming ci
    if(rid<=n){
        cout<<1<<" "<<rid;
        return 0;
    }//zai di yi pai
    int t;
    t=n+1;
    y=m;
    while(t!=rid){
        //if(x>n) break;
        //if(y>m) break;
        if(x%2==0){
            //ou shu
            for(int i=m;i>=1;i--){
                t++;
                y--;
            }
            y=1;
            x++;
        }
        else{
            for(int i=1;i<=m;i++){
                t++;
                y++;
            }
            y=m;
            x++;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}

