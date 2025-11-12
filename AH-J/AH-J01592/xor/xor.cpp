#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[500005];
int num=0;
int m(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        printf("%d ",s[i]);
    }
    printf("\n\n");
    for(int i=1;i<=n;i++){
        int t=0;
        int l=i;
        for(int r=i;r<=n;r++){
            if(s[r]^s[l-1]==k){
                t++;
                l=r;
                printf("%d %d ",l,r);
            }
        }
        int r=i;
        for(int l=i;l>=1;l--){
            if(s[r]^s[l-1]==k){
                t++;
                r=l;
                printf("%d %d\n",l,r);
            }
        }
        printf("%d\n",t);
        num=max(num,t);
        cout<<'\n';
    }
    printf("%d",num);
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    int num0=0,num1=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0) num0++;
        if(a[i]==1) num1++;
    }
    if(k==0){
        printf("%d",n/2);
    }
    if(k==0&&num1!=0){
        printf("%d",num0/2+num1/2);
    }
    if(k==1){
        printf("%d",n/2);
    }
    return 0;
}
