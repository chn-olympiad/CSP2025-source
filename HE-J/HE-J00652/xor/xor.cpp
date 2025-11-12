#include<cstdio>
#include<algorithm>
using namespace std;
int a[500001],p,n,x,t,ans=0;
bool pasted[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int l=1;l<=n;l++){
        int tmp=a[l];
        if(pasted[l]){
            continue;
        }
        if(a[l]==x){
            ans++;
            pasted[l]=1;
            continue;
        }
        for(int r=l+1;r<=n;r++){
            if(pasted[r]){
                break;
            }
            tmp=(tmp^a[r]);
            if(tmp==x){
                for(int i=l;i<=r;i++){
                    pasted[i]=true;
                }
                ans++;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
