#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);//hang,lie
    for(int i=1;i<=n*m;i++){
        scanf("%d",&num[i]);
    }
    int ch=num[1];

    for(int i=1;i<=n*m;i++){
        int ma=i;
        for(int j=i+1;j<=n*m;j++){
            if(num[j]>num[ma]){
                ma=j;
            }

        }
        swap(num[ma],num[i]);
    }
    //
    int cha;
    for(int i=1;i<=n*m;i++){
        if(num[i]==ch){
            cha=i;
            break;
        }
    }
    //
    for(int i=1,j=1,sum=1;;sum++){//lie,hang
        if(sum==cha){
            printf("%d %d",i,j);
            break;
        }
        if(i%2==1){
            j++;
            if(j==n+1){
                i++;
                j--;
            }
        }else{
            j--;
            if(j==0){
                i++;
                j++;
            }
        }
        //

    }
    return 0;
}
