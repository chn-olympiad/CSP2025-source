#include <iostream>

using namespace std;
int num[205];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,j=1;
    scanf("%d%d",&n,&m);
    scanf("%d",&num[1]);
    for(int i=2;i<=n*m;i++){
        scanf("%d",&num[i]);
        if(num[i]>num[1])j++;
    }
    //cout<<j<<"aa";
    if(j%n==0){
            printf("%d ",j/n);
            if(j/n%2==0){
                    printf("1");

            }
            else{
                printf("%d",n);
            }
    }
    else{
        printf("%d ",j/n+1);
        if((j/n+1)%2==0){
            printf("%d",n-(j%n)+1);
        }
        else{
            printf("%d",j%n);
        }
    }
    return 0;
}
