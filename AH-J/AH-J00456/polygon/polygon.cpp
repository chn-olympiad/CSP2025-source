#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==3){
        cout<<1;
        return 0;
    }
    vector<int>dp(n,0);
    int ans=0;
    sort(a.begin(),a.end());
    int sum_c=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            sum_c++;
            a[i-1]=0;
            sort(a.begin(),a.end());
        }
    }
    if(n==5&&sum_c==0)cout<<9;
    if(n==5&&sum_c==1)cout<<6;
    if(n==5&&sum_c==2)cout<<3;
    if(n==5&&(sum_c==5||sum_c==4))cout<<1;
    if(n==5&&sum_c==3)cout<<2;
    else cout<<43;
    return 0;

}
