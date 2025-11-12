#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[103];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n,m,R,r;
    cin>>n>>m;

    int p=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int t;
            cin>>t;
            if(i==1 && j==1) r=t;
            a[p++]=t;
        }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r) R=i;
    }
    int N=1,M=1;
    for(int i=2;i<=R;i++){
        if(M%2){
            if(N<=n-1) N++;
            else M++;
        } else{
            if(N>=2) N--;
            else M++;
        }
    }
    cout<<M<<' '<<N<<endl;
    return 0;
}
