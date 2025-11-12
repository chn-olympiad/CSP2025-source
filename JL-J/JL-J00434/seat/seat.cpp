#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int a[110][110],b[N];
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum,s=0,os=0;
    cin>>n>>m>>sum;
    b[1]=sum;
    for(int i=2;i<=n*m;i++) cin>>b[i];
    sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int h=1;h<=n;h++){
                s++;
                a[h][i]=b[s];
                if(b[s]==sum){
                    cout<<i<<" "<<h;
                    return 0;
                }
            }
        }else{
            for(int h=n;h>=1;h--){
                s++;
                a[h][i]=b[s];
                if(b[s]==sum){
                    cout<<i<<" "<<h;
                    return 0;
                }
            }
        }
    }

    return 0;
}
