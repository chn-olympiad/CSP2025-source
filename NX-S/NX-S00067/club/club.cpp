#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1001;
int a[N][N];
int aa[N];
long long ans;
int maxi(int n1,int n2,int n3){
    int i=max(max(n1,n2),n3);
    if(i==n1)return 1;
    if(i==n2)return 2;
    return 3;
}
bool cmp(int n1,int n2){
    return n1>n2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int lim=n>>1;
        int fa=0,fb=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0)fa=1;
            if(a[i][3]!=0)fb=1;
        }
        if(n==2){
            int maxn=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j)continue;
                    maxn=max(maxn,a[1][i]+a[2][j]);
                }
            }
            cout<<maxn;
        }
        if(fa==0){
            for(int i=1;i<=n;i++){
                aa[i]=a[i][1];
            }
            sort(aa+1,aa+n+1,cmp);
            for(int i=1;i<=lim;i++){
                ans+=aa[i];
            }
            cout<<ans;
        }

    }

    return 0;
}
