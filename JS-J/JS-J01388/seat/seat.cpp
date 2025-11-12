#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,cmp,b[105],d;
int research(int l,int r,int key){
    int mid=(l+r)/2;
    if(b[mid]==key) return mid;
    else{
        if(b[mid]>key) return research(l,mid-1,key);
        else return research(mid+1,r,key);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+m*n);
    d=m*n+1-research(1,m*n,a[1]);
    for(int i=1;i<n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[i]<a[j]){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cmp++;
                if(d==cmp) cout<<i<<" "<<j;
            }
        }
        else{
            for(int j=n;j>0;j--){
                cmp++;
                if(d==cmp) cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
