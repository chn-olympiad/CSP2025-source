#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
vector<int>m[N];
int n,k;
int a[500005];
int b[500005];
int ans[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
        m[b[i]].push_back(i);
    }
    for(int i=n;i>=1;i--){
        bool f=0;
        int c=0;
        int tmp=k^b[i-1];
        if(m[tmp].size()){
            int l=0,r=m[tmp].size()-1,mid,ans=0;
            while(l<=r){
                mid=(l+r)/2;
                if(m[tmp][mid]>=i){
                    ans=m[tmp][mid];
                    r=mid-1;
                }
                else l=mid+1;
            }
            c=ans;
        }
        if(c>=i)f=1;
        ans[i]=ans[i+1];
        if(f==1){
            ans[i]=max(ans[i],1+ans[c+1]);
        }
        //cout<<ans[i]<<" ";
    }
    cout<<ans[1];
    return 0;
}
