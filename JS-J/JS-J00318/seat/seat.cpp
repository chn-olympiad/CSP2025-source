#include <bits/stdc++.h>
#define N 105
using namespace std;
pair<int,int> a[N];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.first>y.first;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt,h,l=0;
    cin>>n>>m;
    int sz=n*m;
    for(int i=1;i<=sz;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+sz+1,cmp);
    for(int i=1;i<=sz;i++){
        if(a[i].second==1)
            cnt=i;
    }
    l=(cnt+n-1)/n;
    int ys=cnt%n;
    if(ys==0)
        ys=n;
    if(l%2==1)
        h=ys%n;
    else{
        h=n-ys+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
