#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 100 ;
int n,m,k,f,a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    f=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++){
        if(f==a[i]){
            f=i;
            break;
        }
    }
    int u=ceil(f*1.0/n),v=f%n;
    if(v==0) v=n;
    if(u%2==0){
        cout<<u<<' '<<m+1-v<<endl;
    }
    else{
        cout<<u<<' '<<v<<endl;
    }
    return 0;
}
