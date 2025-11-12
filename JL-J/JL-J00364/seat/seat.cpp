#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[120]={0};
    int b[12][12]={0};
    int m,n;
    scanf("%d%d",&m,&n);
    int k=m*n;
    for(int i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
    int num=a[0];
    sort(a,a+k,cmp);
    int x=0,y=0,j=0;
    bool t=0,f=0;
    while(j<k){
        b[x][y]=a[j];
        if((x==n-1 or (x==0 and y!=0)) and f!=1){
            f=1;
            y++;
            if(t) t-=1;
            else t+=1;
        }
        else if(t==0){
            x++;
            f=0;
        }
        else if(t==1){
            x--;
            f=0;
        }
        j++;
    }
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(b[i][q]==num){
                printf("%d %d",q+1,i+1);
            }
        }
    }
    return 0;
}
