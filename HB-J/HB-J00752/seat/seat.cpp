#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int b[1005];
int c[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int y,x;
    scanf("%d%d",&y,&x);
    int xiaor;
    for(int i=1;i<=y*x;i++){
        scanf("%d",&b[i]);
        if(i==1)
            xiaor=b[i];
    }
    int r_place=1;
    for(int i=1;i<=y*x;i++){
        for(int j=1;j<y*x;j++){
            if(b[j]<b[j+1]){
                swap(b[j],b[j+1]);
                if(j==r_place) r_place++;
            }
        }
    }
    int x1=1,y1=1;
    int dirsx=1;
    int dirzy=0;
    for(int i=2;i<=r_place;i++){
        if(x1==x && dirsx==1 && dirzy==0){
            dirsx=0;
            dirzy=1;
        }
        else if(x1==x && dirsx==0 && dirzy==1){
            dirsx=-1;
            dirzy=0;
        }
        else if(x1==1 && dirsx==-1 && dirzy==0){
            dirsx=0;
            dirzy=1;
        }
        else if(x1==1 && dirsx==0 && dirzy==1){
            dirsx=1;
            dirzy=0;
        }
        x1+=dirsx;
        y1+=dirzy;
    }
    printf("%d %d",y1,x1);
    return 0;
}
