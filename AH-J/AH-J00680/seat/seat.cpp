#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int n,m;
int wo,a[2000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }wo=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==wo){
            wo=i;
            break;
        }
    }int mm=(wo-1)/n+1;
    int nn=(wo-1)%n+1;
    if(mm%2==0){
        nn=n-nn+1;
    }
    cout<<mm<<" "<<nn;
    return 0;
}
