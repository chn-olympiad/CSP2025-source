#include<bits/stdc++.h>
using namespace std;
int n,m,a,littleR,t[114],littleR_nums,s_1=1,s_2=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x=n*m;
    for(int i=1;i<=x;i++){
        scanf("%d",&a);
        if(i==1) littleR=a;
        t[a]++;
    }
    for(int i=100;i>=0;i--){
        if(i==littleR){
            littleR_nums=s_1;
            break;
        }else if(t[i]) s_1++;
    }
    int i=1,j=1;
    while(s_2<=x){
        //printf("%d %d\n",j,i);
        if(j%2==1){
            if(s_2==littleR_nums){
                printf("%d %d\n",j,i);
                break;
            }

            if(i==n){
                j++;
                s_2++;
            }else{
                i++;
                s_2++;
            }
        }else{
            if(s_2==littleR_nums){
                printf("%d %d\n",j,i);
                break;
            }
            if(i==1){
                j++;
                s_2++;
            }else{
                i--;
                s_2++;
            }
        }

    }
    return 0;
}
