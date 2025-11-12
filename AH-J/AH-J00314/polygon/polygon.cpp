#include<iostream>
#include<map>
using namespace std;
const int N=5005;
int a[N];
map<__int128,bool>mp;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans=0;
    for( int i=0;i<=(1<<n);i++){
        int mx=0,tot=0,cnt=0;
        __int128 k=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                if(a[j]>mx)mx=a[j];
                tot+=a[j];
                cnt++;
                //cout<<a[j]<<" ";
                k=k*100+j+1;
                if(cnt>=3&&tot>mx*2&&mp[k]==0){
                        //cout<<" Y ";
                    mp[k]=1;
                    ans++;
                }

            }
        }
        //cout<<'\n';
    }
    cout<<ans;
    return 0;
}
