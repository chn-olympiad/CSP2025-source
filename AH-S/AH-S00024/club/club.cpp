#include<bits/stdc++.h>
using namespace std;
long long t,a[1000005][3],n[1000005],c[1000005];
bool cmp(int x,int y){
    return x>y;
}
int main(void){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        memset(a,0,sizeof(a));
        long long cnt=0;
        for(int j=1;j<=n[i];j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            c[j]=a[j][1];
        }
        sort(c+1,c+n[i]+1,cmp);
        for(int j=1;j<=n[i]/2;j++){
            cnt+=c[j];
        }
        cout<<cnt;
        return 0;
    }
    return 0;
}
