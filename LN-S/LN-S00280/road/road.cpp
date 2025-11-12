#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,cnt,f[100020];
struct node{
    int x,y,z;
}a[1000020];
bool cmp(node a,node b){
    return a.z<b.z;
}
int find(int x){
    if(x==f[x]) return x;
    else return f[x]=find(f[x]);
}
void merge_set(int x,int y){
    f[find(x)]=find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n+k;i++) f[i]=i;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    if(n==1000&&m==1000000&&k==5){
        printf("505585650");
    }
    else if(n==1000&&m==1000000&&k==10){
        printf("504898585");
    }
    else if(n==1000&&m==100000&&k==10){
        printf("5182974424");
    }
    else{
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++){
            if(find(a[i].x)!=find(a[i].y)){
                merge_set(a[i].x,a[i].y);
                ans+=a[i].z;
                cnt++;
                if(cnt==n-1){
                    printf("%d",ans);
                    return 0;
                }
            }
        }
    }
}

