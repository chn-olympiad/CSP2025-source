#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,K=1e6+1e5;
int n,k;
int a[N],sum[N];
int nxt[N],minnxt[N];
vector<int> vec[K];
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    vec[0].push_back(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        vec[sum[i]].push_back(i);
    }
    for(int i=0;i<=n+1;i++){
        nxt[i]=minnxt[i]=2e9;
    }
    for(int i=0;i<=1048575;i++){
        int l=0,r=0;
        int size1=vec[i].size();
        int size2=vec[i^k].size();
        while(l<size1 && r<size2){
            int a=vec[i][l]+1,b=vec[i^k][r],c=0;
            if(r>=1){
                c=vec[i^k][r-1];
            }
            if(a<=b){
                if(a>c){
                    nxt[a]=min(nxt[a],b);
                }
                l++;
            }else{
                r++;
            }
        }
    }
/*    for(int i=1;i<=n;i++){
        cout<<nxt[i]<<" ";
    }*/
    for(int i=n;i>=1;i--){
        minnxt[i]=min(minnxt[i+1],nxt[i]);
    }
    for(int i=minnxt[1];i<=n;i=minnxt[i+1]){
        ans++;

    }
    cout<<ans;
    return 0;
}
