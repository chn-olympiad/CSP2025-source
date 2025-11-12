#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,idx,ans,a[N],b[N],l[N],r[N];
bool check(int x,int y){
    int ans=0;
    for(int i=x;i<=y;i++){
        ans^=a[i];
    }
    return ans==k;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(check(i,j)){
                    idx++;
                    l[idx]=i;
                    r[idx]=j;
                    b[i]++;
                    b[j+1]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        b[i]=b[i]+b[i-1];
    }
    bool flag=1;
    for(int i=1;i<=idx;i++){
        int t=b[l[i]];
        flag=1;
        for(int j=l[i];j<=r[i];j++){
            if(t!=b[j]) flag=0;
        }
        if(flag) ans++;
    }
    cout<<ans;
    return 0;
}
