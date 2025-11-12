#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500011];
int s[500011];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    int ans=0;
    int need=k;
    for(int i=1;i<=n;i++){
        if(s[i]==need){
            ans++;
            if(s[i]==k) need=0;
            else need=k;
            //printf("need:%d i:%d\n",need,i);
        }
    }
    printf("%d",ans);
    return 0;
}
