#include <bits/stdc++.h>
using namespace std;
int n,k,t,a[500001],s[500001],ans;
bool b[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
        if(i==1){
            s[i]=a[i];
        }
    }
    /*for(int i=1;i<=n;i++){
        printf("%d ",s[i]);
    }*/
    //printf("\n");
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            t=i;
        }
        else{
            int tmp=s[i]^s[t];
            if(tmp==k){
                //cout<<1<<' '<<tmp<<"\n";
                ans++;
                t=i;
                continue;
            }
            for(int j=t+1;j<i;j++){
                int xo=s[i]^s[j];
                if(xo==k){
                    //cout<<2<<' '<<s[i]<<' '<<s[j]<<"\n";
                    //printf("%d %d\n",xo,k);
                    t=i;
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
