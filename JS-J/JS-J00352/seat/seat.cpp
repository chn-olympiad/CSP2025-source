#include<bits/stdc++.h>
using namespace std;
struct po{
    int p;
    int id;
}a[10000];
bool cmp(po a,po b){
    return a.p>b.p;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].p;
        a[i].id=i;
    }
    int l=1,r=1;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            cout<<r;
            cout<<" ";
            if(r%2==1){
                cout<<l;
            }
            else{
                cout<<n-l+1;
            }

            return 0;
        }
        if(l==n){
            l=1;
            r++;
        }
        else{
            l++;
        }
    }
    return 0;
}
