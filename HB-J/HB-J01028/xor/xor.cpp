#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,l[500005];
bool fl,fll;
void findx(int p,int w){
    ans=max(ans,w);
    for(int i=p;i<=n;i++){
        if(l[i]==1919810000)continue;
        findx(l[i]+1,w+1);
    }
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1)fl=true;
        if((a[i]!=1)&&(a[i]!=0))fll=true;
    }
    if((!fl)&&(!k)){
        printf("%d",n/2);
    }else if((!fll)&&(!k)){
        for(int i=1;i<=n;i++){
            if(!a[i])ans+=1;
            if((a[i]==a[i+1])&&(a[i])){
                ans+=1;
                i+=1;
            }
        }
        printf("%d",ans);
    }else if((!fll)&&k){
        for(int i=1;i<=n;i++){
            if(a[i])ans+=1;
        }
        printf("%d",ans);
    }else{
        for(int i=1;i<=n;i++)l[i]=1919810000;
        for(int i=1;i<=n;i++){
            if(a[i]==k)l[i]=i;
            else{
                int o=a[i];
                for(int ind=i+1;ind<=n;ind++){
                    o^=a[ind];
                    if(o==k){
                        l[i]=ind;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(l[i]==1919810000)continue;
            findx(l[i]+1,1);
        }
        printf("%d",ans);
    }
    return 0;
}
