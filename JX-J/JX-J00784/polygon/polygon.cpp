#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int n,a[N],s[N],sorta[N],cnt=0,maxa,len;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];// 1 2 3 4 5 == 1 3 6 10 15
        maxa=max(maxa,a[i]);//1 2 3 4 5
    }
    len=s[n];
    if(len>2*maxa){
        cnt++;
    }
    cout<<cnt;//go 1-3
    return 0;
}
/*
for(int l=3;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            sorta[i][i+l-1]=max(sorta[i+1][l-1],sorta[i+l-1][2]);
        }
    }
       for(int l=3;l<=n;l++){
        for(int i=l+1;i<=n;i++){
            len=s[i]-a[i-l];//len(i,i-l)
            maxa=sorta[i-l][i];
            if(len>2*maxa){
                cnt++;
                cout<<i-l<<" "<<i<<endl;
            }
        }
    }*/
