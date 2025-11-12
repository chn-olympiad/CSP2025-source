#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500001];
void flb(){
    int num0=0;
    int num1=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            num0++;
        }
        else{
            num1++;
        }
    }
    if(k==0){
        printf("%d",num0+num1/2);
    }
    else{
        int cnt;
        if(num0<num1){
            cnt=num0;
            num1-=num0;
        }
        else if(num0==num1){
            cnt=num0;
            num1-=num0;
        }
        else{
            cnt=num1;
            num0-=num1;
        }
        cnt+=num1/3;
        printf("%d",cnt);
    }
}
void flc(){
    int num=0;
    for(int i=1;i<=n;i++){
        num^=a[i];
    }
    if(num==k){
         printf("1");
    }
    else{
        int cnt=0;
        for(int i=n;i>=1;i--){
            num^=a[i];
            if(num==k){
                cnt++;
            }
        }
        printf("%d",cnt+1);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    bool flaga=true;
    bool flagb=true;
    bool flagc=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1){
            flaga=false;
        }
        if(a[i]>1){
            flagb=false;
        }
        if(a[i]>255){
            flagc=false;
        }
    }
    if(flaga==true){
        printf("%d",n);
        return 0;
    }
    if(flagb==true){
        flb();
        return 0;
    }
    sort(a+1,a+n+1);
    if(flagc==true){
        flc();
        return 0;
    }
    else{
        flc();
    }
    return 0;
}
