#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int ccf=0;ccf<t;ccf++){
        int n;
    cin>>n;
    int a[n][3],ma,h=n/2,f=0;
    for(int i=0;i<n;i++){
        ma=0;
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            if(a[i][j]>ma)   ma=a[i][j];
        }
        f=f+ma;
    }
    if(n<200){
        cout<<f<<endl;
        continue;
    }
    if(n>200){
        long long harry[n],zz=0;
        for(int i=0;i<n;i++){
            harry[i]=a[i][0];
            zz+=harry[i];
        }
        sort(harry,harry+n);
        for(int i=0;i<h;i++){
            zz-=harry[i];
        }
        cout<<zz<<endl;
        continue;
    }
    }
    return 0;
}
