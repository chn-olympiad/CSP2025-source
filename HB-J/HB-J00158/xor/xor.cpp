#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,last,ans,sum1,sum2;
int a[500005];
struct node{
    int x;int y;
}t[1000005];
bool cmp(node a,node b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n<=1000){
        for(int i=1;i<=n;i++){
            int res=0;
            for(int j=i;j<=n;j++){
                res^=a[j];
                if(res==k) ++cnt,t[cnt].x=i,t[cnt].y=j;
            }
        }
        sort(t+1,t+1+cnt,cmp);
        for(int i=1;i<=cnt;i++){
            if(t[i].x>last) ans++,last=t[i].y;
            else if(t[i].x<last&&t[i].y<=last) last=t[i].y;
        }
        cout<<ans;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==1) sum1++;
            else sum2++;
        }
        if(k==0) cout<<sum2;
        else cout<<sum1;
    }
    return 0;
}