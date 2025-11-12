#include<bits/stdc++.h>
#define maxn 11
#define maxm 11
using namespace std;
int mp[maxm][maxn];
int a[maxn*maxm];
int n,m,sc,tend,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);  
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    sc=a[1];
    sort(a,a+(n*m+1));
    // for(int i=1;i<=n*m;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;
    for(int i=1;i<=m*n;i++){
        if(a[i]==sc){
            tend=i;
        }
    }
    // cout<<tend<<endl;
    tend=n*m-tend+1;
    // cout<<tend<<endl;
    x=tend%n==0?tend/n:(tend/n)+1;
    y=(tend/n%2==0||tend%n==0)?(tend%n==0?m:tend%n):m-tend%n+1;
    printf("%d %d",x,y);
    fclose(stdin);
    fclose(stdout);
    return 0;
}