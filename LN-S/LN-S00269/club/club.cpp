#include<bits/stdc++.h>
using namespace std;
long long t,n,a[1000005][4],d1,d2,d3,ans;
int ad1(int a){
    if (d1<sum){
        ans+=a[i][1];
        d1++;
    }
    else{
        if (a[i][2]>a[i][3]){
            if (d2<sum){
                ans+=a[i][2];
                d2++;
            }
            else{
                d3++;
                ans+=a[i][3];
            }
        }
    }
}
int ad2(int a[i][1],int a[i][2],int a[i][3]){
    if (d2<sum){
        ans+=a[i][2];
        d2++;
    }
    else{
        if (a[i][1]>a[i][3]){
            if (d1<sum){
                ans+=a[i][1];
                d1++;
            }
            else{
                d3++;
                ans+=a[i][3];
            }
        }
    }
}
int ad3(int a[i][1],int a[i][2],int a[i][3]){
    if (d3<sum){
        ans+=a[i][3];
        d3++;
    }
    else{
        if (a[i][2]>a[i][1]){
            if (d2<=sum){
                ans+=a[i][2];
                d2++;
            }
            else{
                d1++;
                ans+=a[i][1];
            }
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t>>n;
    int sum=n/2;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=3;j++){
            cin>>a[i][j];
            if (a[i][1]>a[i][2] && a[i][1]>a[i][3]){

                ad1(a[i][1],a[i][2],a[i][3]);


            }
            else if (a[i][2]>a[i][1] && a[i][2]>d[i][3]){

                ad2(a[i][1],a[i][2],a[i][3]);
            }
            else{
                ad3(a[i][1],a[i][2],a[i][3]);
            }
        }
    }
    cout<<ans;
    return 0;
}
