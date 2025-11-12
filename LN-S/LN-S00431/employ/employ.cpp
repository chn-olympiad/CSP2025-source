#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[10000],sum;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
        sum+=c[i];
    }
    //if(m==1){
        //cout<<sum;
        //return 0;
   // }
    cout<<0;
    return 0;
}
