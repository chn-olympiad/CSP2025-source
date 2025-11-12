#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node{
    int v,id;
    bool operator <(const node &A) const{
        return v>A.v;
    }
}a[N];
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].v;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1);
    int nc=1,nr=1,now=1;
    while(1){
        if(a[now].id==1){
            cout<<nc<<" "<<nr;
            return 0;
        }
        now++;
        if(nc&1){
            if(nr==n)  nc++;
            else  nr++;
        }
        else{
            if(nr==1)  nc++;
            else  nr--;
        }
    }
    return 0;
}
