#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
        int n,a[100010][4],maxx[4],maxpos,b[100010],anss;
        cin>>n;
        for(int i=1;i<=n;i++){
            int ans=-1,pos=0;
            maxx[i] = 0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>ans){
                    ans = a[i][j];
                    pos = j;
                }
            }
            b[i] = ans;
            maxx[pos]++;
        }
        for(int i=1;i<=n;i++){
            maxpos = max(maxpos,maxx[i]);
        }
        if(maxpos<=n/2){
            for(int i=1;i<=n;i++){
                anss+=b[i];
            }
            cout<<anss;
        }
    }
    return 0;
}
