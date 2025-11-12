#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1005];
long long s[105][105];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long s;
    cin>>s;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    long long x=1,y=1;
    long long i=1;
    bool p=true;//false xiangqian true xianghou
    while(1){
        if(s<a[i]){
            cout<<y<<" "<<x;
            return 0;
        }
        if(i==n*m-1){
            cout<<y<<" "<<x;
            return 0;
        }
        if(p){
            x++;
        }else{
            x--;
        }
        if(x==0) y++;
        if(x==n+1) y++,x--;
    }
    return 0;
}
