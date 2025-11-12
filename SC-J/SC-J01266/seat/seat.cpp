#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
void Work(){
    cin>>n>>m;
    for(int i=1;i<=n*m;++i) cin>>a[i];
    int num=0;
    for(int i=2;i<=n*m;++i) num+=(a[i]>a[1]);
    int x=1,y=1;
    while(num--){
        if(y&1){
            if(x==n) ++y;
            else ++x;
        }else{
            if(x==1) ++y;
            else --x;
        }
    }
    printf("%d %d\n",y,x);
}
int main(){
    freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    Work();
    fclose(stdin),fclose(stdout);
    return 0;
}