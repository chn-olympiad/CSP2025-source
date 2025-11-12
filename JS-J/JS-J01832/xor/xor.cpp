#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],q[100010],len,m;
bool bo=1;
struct st{
    int l,r;
};

int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    st b[100010];
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1){
            bo=0;
        }

    }
    if(bo&&k==0){
        if(n%2==0){
            printf("%d",n/2);
        }else{
            printf("%d",(n-1)/2);
        }
        return 0;
    }

    q[1]=a[1];
    for(int i=2;i<=n;i++){
        q[i]=a[i]^q[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){

            m=q[i]^q[j-1];
            if(m==k){
                b[len].r=i,b[len].l=j;
                len++;
            }

        }

    }
    printf("%d",len);
    return 0;
}
