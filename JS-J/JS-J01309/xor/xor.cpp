#include <bits/stdc++.h>
using namespace std;

int a[500005];

int p(int left,int right){
    int ans=a[left];
    for(int t=left+1;t<=right;t++){
        ans=(ans&a[t])+(ans|a[t]);
    }
    return ans;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int t=1;t<=n;t++){
        cin>>a[t];
    }
    for(int left=1;left<=n;left++){
        int right=left;
        while(p(left,right)!=k && right<=n){
            right++;
        }
        ans++;
        left=right;
    }
    cout<<ans<<endl;
    return 0;
}
