#include <bits/stdc++.h>
using namespace std;
int a[3][100005];
int main(){
    int T,n;cin>>T;
    while(T--){
        cin>>n;int maxn=0,maxs=0,maxth=0,maxd=0;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                if(j==1) if(a[i][1]>maxn) maxn=a[i][1];
                if(j==2) if(a[i][2]>maxs) maxs=a[i][2];
                if(j==3) if(a[i][3]>maxth) maxth=a[i][3];
                if(j==4) if(a[i][4]>maxd) maxd=a[i][4];
            }
        }
        cout<<(maxn+maxs+maxth+maxd)<<endl;
    }
    return 0;
}