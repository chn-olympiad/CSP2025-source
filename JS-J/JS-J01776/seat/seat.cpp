#include<bits/stdc++.h>
#define Maxn 1000+10
using namespace std;
int n,m;
int a[Maxn];
int x,y;
int d;
void free(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
}
void xu(){
    for(int i=1;i<n*m-1;i++)
        for(int j=1;j<n*m-1;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
    }
}
int main(){
    free();
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<n*m;i++){
        scanf("%d",&a[i]);
    }
    xu();
    int noww=1;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                if(a[noww]<d){
                    printf("%d %d",i,j);
                    return 0;
                }
                else noww++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[noww]<d){
                    printf("%d %d",i,j);
                    return 0;
                }
                else noww++;
            }
        }
    }
    return 0;
}
