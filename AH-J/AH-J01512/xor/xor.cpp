#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+10;
int n,k,a[N],sum;
int yh(int a,int b){
    int a2[30],b2[30],la,lb,mxl,ans[30];
    while(a){
        a2[++la]=a%2;
        a/=2;
    }
    while(b){
        b2[++lb]=b%2;
        b/=2;
    }
    mxl=max(la,lb);
    for(int i=1;i<=mxl;i++){
        if(a2[i]==1&&b2[i]==0||a2[i]==0&&b2[i]==1){
            ans[i]=1;
        }else{
            ans[i]=0;
        }
    }
    int cnt=0;
    for(int i=mxl;i>=1;i--){
        cnt+=ans[i]*pow(2,i-1);
    }
    return cnt;
}
struct node{
    int s,t;
}q[N];
bool cmp(node a,node b){
    return a.t<b.t;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=i;j<=n;j++){
            cnt=yh(cnt,a[j]);
            if(cnt==k){
                sum++;
                q[sum].s=i;q[sum].t=j;
            }
            j++;
        }
    }
    sort(q+1,q+sum+1,cmp);
    int ans=0,end=0;
    for(int i=1;i<=sum;i++){
        if(q[i].s>end){
            ans++;
            end=q[i].t;
        }
    }
    cout<<ans;
    return 0;
}
