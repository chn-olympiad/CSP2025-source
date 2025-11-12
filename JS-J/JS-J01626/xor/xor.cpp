#include<bits/stdc++.h>
using namespace std;
struct node{
    int s,e;
}s[500005];
bool cmp1(node x,node y){
    if(x.e==y.e)
        return x.s>y.s;
    return x.e<y.e;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0,a[500005],sum[500005],ans=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sum[0]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]^a[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp=sum[i]^sum[j];
            if(tmp==k){
                s[++cnt].s=i+1,s[cnt].e=j;
            }
        }
    }
    sort(s+1,s+cnt+1,cmp1);
    int nt=0,np=1;
    while(1){
        bool f=0;
        for(int i=np;i<=cnt;i++){
            if(s[i].s>nt){
                nt=s[i].e;
                np=i;
                ans++;
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
