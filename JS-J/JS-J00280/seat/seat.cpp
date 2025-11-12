#include<bits/stdc++.h>
using namespace std;
int n,m,a[114];
int t,fn,c=0;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&m,&n);
    int k = n*m;
    for(int i=1;i<=k;i++){
       scanf("%d",&a[i]);
    }t = a[1];sort(a+1,a+1+k,cmp);
    for(int i=1;i<=k;i++){
        if(a[i] == t){fn = i;break;}
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                c++;
                if(c == fn){printf("%d %d",i,j);return 0;}
            }
        }else{
            for(int j=m;j>=1;j--){
                c++;
                if(c == fn){printf("%d %d",i,j);return 0;}
            }
        }


    }
    return 0;
}
