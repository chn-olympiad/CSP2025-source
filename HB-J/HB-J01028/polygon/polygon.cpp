#include<bits/stdc++.h>
using namespace std;
int n,a[5005],c[30],ans,e=998244353,ed[5005];
bool fl;
void findx(int sum,int p,int ind){
    if(p>sum){
        int sumi=0,maxi=0;
        for(int i=1;i<=sum;i++){
            sumi+=c[i];
            maxi=max(maxi,c[i]);
        }
        if(sumi>2*maxi){
            ans+=1;
            if(ans>e)ans-=e;
        }
        return ;
    }
    for(int i=ind;i<=n-sum+p;i++){
        c[p]=a[i];
        findx(sum,p+1,i+1);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1)fl=true;
    }
    if((!fl)&&n>=20){
        ed[1]=1;
        for(int i=2;i<=n;i++)ed[i]=(ed[i-1]*i)%e;
        for(int m=3;m<=n;m++){
            int l=0;
            if(ed[n]<ed[m]*ed[n-m])l=ed[n]+e;
            else l=ed[n];
            ans=(ans+(l/(ed[m]*ed[n-m])))%e;
        }
        printf("%d",ans);
    }else{
        for(int m=3;m<=n;m++)findx(m,1,1);
        printf("%d",ans);
    }
    return 0;
}
