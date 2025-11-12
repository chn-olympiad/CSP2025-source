#include<cstdio>
#include<algorithm>
using namespace std;
int stu[101],n,m,yang,tmp=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&stu[i]);
    }
    yang=stu[1];
    sort(stu+1,stu+n*m+1,cmp);
    for(int i=1;i<=m;){
        int j=1;
        for(;j<=n;j++){
            if(stu[tmp++]==yang){
                printf("%d %d",i,j);
                return 0;
            }
        }
        i++;
        for(j--;j>=1;j--){
            if(stu[tmp++]==yang){
                printf("%d %d",i,j);
                return 0;
            }
        }
        i++;
    }
    return 0;
}
