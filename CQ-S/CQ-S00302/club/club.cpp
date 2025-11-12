#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,a[N][3],b[3];
priority_queue<int> q[3];
void sol(){
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<3;i++){
        b[i]=0;
        while(q[i].size())q[i].pop();
    }
    for(int i=1;i<=n;i++){
        int mx=0,mx2=-1e9;
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
            mx=a[i][j]>a[i][mx]?j:mx;
        }
        for(int j=0;j<3;j++)if(j!=mx){
            mx2=max(mx2,a[i][j]-a[i][mx]);
        }
        sum+=a[i][mx];
        b[mx]++;
        q[mx].push(mx2);
    }
    for(int j=0;j<3;j++){
        while(b[j]>n/2)
            sum+=q[j].top(),q[j].pop(),--b[j];
    }
    printf("%d\n",sum);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;scanf("%d",&t);while(t--)sol();
}
