#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
int res=-1;
int bl(int ar,int br,int cr,int now,int he){
    if(ar > n/2 || br> n/2 || cr> n/2){
        return 0;
    }
    if(now == n-1){
        res = max(res,he);
        return 0;
    }
    bl(ar + 1,br,cr,now+1,he+a[now+1][1]);
    bl(ar,br + 1,cr,now+1,he+a[now+1][2]);
    bl(ar,br,cr + 1,now+1,he+a[now+1][3]);
    return 0;
}
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        bl(1,0,0,0,a[0][1]);
        bl(0,1,0,0,a[0][2]);
        bl(0,0,1,0,a[0][3]);
        cout<<res<<endl;
        res=-1;
    }

    return 0;
}
