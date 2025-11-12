#include<bits/stdc++.h>
using namespace std;
long long sc;
int a[10000][10000];
long long n,m;
long long h[1000010];
bool cmp(long long x,long long y){
    return x>y;
}
long long lo;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    cin>>sc;
    h[0]=sc;
    for(long long i=1;i<n*m;i++){
        cin>>h[i];
    }
    sort(h,h+n*m,cmp);
    for(long long i=0;i<n*m;i++){
        if (h[i]==sc)
            lo=i;
    }
    long long x=0,y=0;
    for(long long i=0;i<(m+1)/2;i++){
        for(long long j=0;j<n;j++){
            a[y][x]=h[x*n+y];
            if(lo==x*n+y){
                cout<<x+1<<' '<<y+1;
                return 0;
            }
            y++;
        }
        x++;
        for(long long j=0;j<n;j++){
            a[y][x]=h[(x+1)*n-y];
            if(lo==(x+1)*n-y){
                cout<<x+1<<' '<<y;
                return 0;
            }
            y--;
        }
        x++;
    }
    return 0;
}
