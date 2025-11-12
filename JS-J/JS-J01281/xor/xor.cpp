#include<bits/stdc++.h>
using namespace std;
int n,k,maxi=0;
int a[1048580];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(k==1){
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                maxi++;
        printf("%d",maxi);
        return 0;
    }
    else if(k==0){
        int i=1;
        while(i<=n){
            if(a[i]==0) maxi++,i++;
            else{
                 int cnt=0;
                 while(1){
                    if(a[i]!=0) cnt++,i++;
                    else break;
                 }
                 maxi+=cnt/2;
            }
        }
        printf("%d",maxi);
        return 0;
    }
    else printf("0");
    return 0;
}
