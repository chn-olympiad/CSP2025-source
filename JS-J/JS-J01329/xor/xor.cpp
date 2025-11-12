#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    vector<long long>a;
    long long a1;

    for(long long i=1;i<=n;i++){
        cin>>a1;
        a.push_back(a1);
    }
    long long ans=0;

    while(!a.empty()){
        long long siz=a.size()-1;
       // cout<<siz<<endl;
        long long t=0;
        long long i1=0;
        bool p=true;
        for(long long i=siz;i>=0;i--){
            t^=a[i];
            if(t==k){
                ans++;
                i1=i;
                //cout<<t<<' '<<i<<endl;
                break;
            }
            if(i==0){
                p=false;
                a.pop_back();
                break;
            }
        }
        if(p){
            for(long long i=siz;i>=i1;i--){
                a.pop_back();
            }
        }

    }
    cout<<ans;
    cout<<endl;
    return 0;
}
