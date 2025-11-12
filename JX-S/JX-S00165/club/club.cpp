#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[100005][5],d[100005][5],pd[5],last[100005],maxn;

void D(int i,long long s){
    if(i>n){
        if(s>maxn)maxn=s;
        return ;
    }
    for(int j=1;j<=3;j++){
        if(pd[j]<n/2&&d[i][j]==0){
            d[i][j]=1;
            pd[j]++;
            D(i+1,s+=a[i][j]);
            d[i][j]=0;
            pd[j]--;
        }

    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            //a[j][4]=max(a[j][1],max(a[j][2],a[j][3]));
        }
        D(1,0);
        cout<<maxn<<endl;
        maxn=0;
    }
    return 0;
}
