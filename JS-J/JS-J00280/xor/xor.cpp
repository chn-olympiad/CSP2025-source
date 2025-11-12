#include<bits/stdc++.h>
using namespace std;
int n,k,a[514514];
int x_sum,ans,last_ans = -2147483647;
bool flg;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=100&k==0){
        for(int i=1;i<=n;i++){
            if(a[i]!=1){ flg = 1;break;}
        }if(!flg){
            int aaaa = n/2;
            printf("%d",aaaa);
            return 0;
        }
    }
    if(n<=200000&&k<=1){
        int tmp = 0;
        for(int i=1;i<=n;i++){
            if(a[i]!=1&&a[i]!=0){flg = 1;break;}
            else if(a[i] == 1){tmp++;}
        }if(!flg&&k == 0){int aaaa = tmp/2;
            printf("%d",aaaa);
            return 0;}
            else if(!flg && k==1){int aaaa = tmp;
            printf("%d",aaaa);
            return 0;}
    }
    for(int j=1;j<=n;j++){
            x_sum = a[j];
        for(int i=j+1;i<=n;i++){
            if(x_sum == k){
                ans++;
                x_sum = a[i];
            }else x_sum^=a[i];
        }last_ans = max(ans,last_ans);ans = 0;
    }

    printf("%d",last_ans);
}
