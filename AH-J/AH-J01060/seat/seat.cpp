#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105],cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int xr=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int x=1,y=1;
    while(true){
        bool flag=false;
        if(x==1){
            for(;x<=n;x++){
                //cout<<x<<" "<<y<<endl;
                if(a[cnt]==xr){
                    flag=true;
                    break;
                }
                cnt++;
            }
            if(!flag){
                x=n;
            }
        }else{
            for(x=n;x>=1;x--){
                //cout<<x<<" "<<y<<endl;
                if(a[cnt]==xr){
                    flag=true;
                    break;
                }
                cnt++;
            }
            if(!flag){
                x=1;
            }
        }
        if(flag){
            break;
        }
        y++;

    }
    cout<<y<<" "<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
