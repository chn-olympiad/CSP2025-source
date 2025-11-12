#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
       // cout<<s[i];
    }
    long long ans=0;
    for(register long long now=1;now<=(1 << n);now++){
        long long cnt=now;
        //cout<<now<<endl;
        int i=0,cnt_n=0,max_n=-1;
        long long ansf=0;
        while(cnt>=1){
                //cout<<cnt<<"\n";
            if(cnt%2==1){
                //cout<<s[i]<<" ";
                ansf+=s[i];
                cnt_n++;
                max_n=max(max_n,s[i]);
            }
            i++;
            cnt=cnt/2;
        }
        //cout<<endl;
        if(max_n>=3&&ansf>2*max_n){
            ans++;
            ans=ans%mod;
        }
    }
    cout<<ans;
}
