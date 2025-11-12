#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5];
long long maxn;
bool v[100005];
void dfs(int depth,int aa,int bb,int cc,long long sum,int c1,int c2,int c3){
    if(depth==n+1){
        maxn=max(maxn,sum);
        return;
    }
    for(int i=depth;i<=n;i++){
        if(aa<n/2 && v[i]==0 && c1){
            v[i]=1;
            dfs(depth+1,aa+1,bb,cc,sum+a[i][1],c1,c2,c3);
            v[i]=0;
        }
        if(bb<n/2 && v[i]==0 && c2){
            v[i]=1;
            dfs(depth+1,aa,bb+1,cc,sum+a[i][2],c1,c2,c3);
            v[i]=0;
        }
        if(cc<n/2 && v[i]==0 && c3){
            v[i]=1;
            dfs(depth+1,aa,bb,cc+1,sum+a[i][3],c1,c2,c3);
            v[i]=0;
        }
    }
}
void qwe(){
    int num[100005];
    for(int i=1;i<=n;i++){
        num[i]=a[i][1];
    }
    sort(num+1,num+n+1);
    long long sum=0;
    for(int i=n;i>n/2;i--){
        sum+=num[i];
    }
    cout<<sum<<endl;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=0;
        int c[5]={0,0,0,0,0};
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
                if(a[i][j]!=0) c[j]++;
            }
        }
        if(c[2]==0 && c[3]==0){
            qwe();
        }
        else{
            dfs(1,0,0,0,0,c[1],c[2],c[3]);
            cout<<maxn<<endl;
        }
    }
    return 0;
}
