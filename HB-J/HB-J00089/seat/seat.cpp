#include<bits/stdc++.h>
using namespace std;
#define MAXN 110
int ans[MAXN][MAXN],n,m,a[MAXN],num,id,cnt;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    num=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==num){
            id=i;
            break;
        }
    for(int i=1;i<=m;i++){
        if(i%2==0)
            for(int j=n;j>=1;j--){
                cnt++;
                ans[j][i]=cnt;
                if(cnt==id){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        else
            for(int j=1;j<=n;j++){
                cnt++;
                ans[j][i]=cnt;
                if(cnt==id){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
    }
    return 0;
}+\
