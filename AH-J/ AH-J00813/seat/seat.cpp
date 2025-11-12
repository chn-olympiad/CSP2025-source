#include<bits/stdc++.h>
using namespace std;
int n,m;
int maze[15][15];
int a[1005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);//tiny to enormous
    if(m%2==0){
        for(int i=1;i<=m/2;i++){
            int st=a[2*n*(i-1)+1];
            int ed=a[2*n*i];
            if(r<=st&&r>=ed){
                int cnt=0;
                for(int j=(2*n*(i-1)+1);j<=(2*n*i);j++){
                    cnt++;
                    if(r==a[j]){
                        if(cnt<=n){
                            cout<<i*2-1<<" "<<cnt;
                            return 0;
                        }else{
                            cout<<i*2<<" "<<2*n-cnt+1;
                            return 0;
                        }
                    }
                }
            }else{
                continue;
            }
            //2 2for(int j=1;j<=)
        }
    }else{
        for(int i=1;i<=(m+1)/2;i++){
            int st=a[2*n*(i-1)+1];
            int ed=a[2*n*i];
            if(r<=st&&r>=ed){
                int cnt=0;
                for(int j=(2*n*(i-1)+1);j<=(2*n*i);j++){
                    cnt++;
                    if(r==a[j]){
                        if(cnt<=n){
                            cout<<i*2-1<<" "<<cnt;
                            return 0;
                        }else{
                            cout<<i*2<<" "<<2*n-cnt+1;
                            return 0;
                        }
                    }
                }
            }else{
                continue;
            }
            //2 2for(int j=1;j<=)
        }
    }
    return 0;
}
