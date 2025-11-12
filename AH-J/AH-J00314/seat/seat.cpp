#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
pair<int,int> a[110];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.first>y.first;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].second==1){
            int c=ceil(i*1.0/n);
            int r=0;
            if(c%2==1){
                r=(i%n==0?n:i%n);
            }else{
                r=(i%n==0?1:n-(i%n)+1);
            }
            cout<<c<<" "<<r;
            return 0;
        }
    }
    return 0;
}
