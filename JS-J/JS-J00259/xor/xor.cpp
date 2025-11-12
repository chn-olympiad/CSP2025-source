#include<bits/stdc++.h>
#define ll long long
#define u unsigned
using namespace std;
int n,k,a,s[500005],ans,l[500005],r[500005],tt,mx=-1,ans2;
bool f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a==k)ans2++;
        s[i]=s[i-1]^a;
    }
    for(int i=1;i<=n;i++){
        if(i>mx){
            f=0;
            for(int j=i;j<=n&&f==0;j++){
                if((s[j]^s[i-1])==k){
                    ans++;
                    l[tt]=i;
                    r[tt++]=j;
                    mx=max(mx,j);
                    f=1;
                }
            }
        }
    }
    printf("%d\n",max(ans,ans2));
    return 0;
}
