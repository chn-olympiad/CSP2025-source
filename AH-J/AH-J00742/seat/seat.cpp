#include<iostream>
#include<algorithm>
using namespace std;
int num[10010],n,m,q,cnt;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>num[i];
    q=num[1];
    sort(num+1,num+n*m+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2){
            for(int i=1;i<=n;i++){
                ++cnt;
                //cout<<cnt<<i<<' '<<j<<' '<<'\n';
                if(num[cnt]==q){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
        else{
            for(int i=n;i>=1;i--){
                    ++cnt;
                if(num[cnt]==q){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
    }
}
