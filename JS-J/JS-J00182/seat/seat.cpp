#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
struct node{
    long long cmp;
    long long num;
}a[105];
long long paihang=-1,lie=-1,hang=-1;
bool cmp(node q,node p){
    return q.num>p.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=0; i<n*m; i++){
        cin>>a[i].num;
        a[i].cmp=i;
    }
    sort(a,a+n*m,cmp);
    for(long long i=0; i<n*m; i++){
        if(a[i].cmp==0){
            paihang=i;
            break;
        }
    }
    lie=(paihang/n)+1;
    if(lie%2==0){
        hang=n-(paihang%n);
    }
    if(lie%2==1){
        hang=paihang%n+1;
    }
    cout<<lie<<' '<<hang;
    return 0;
}
