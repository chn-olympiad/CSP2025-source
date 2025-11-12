#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[5][N];
int f[N][5];
int d[20050];
struct node{
    int a,b,c;

} b[N][9];
bool cmp(int x,int y){
    return x>y;
}
//int findd(int x){
//}
//int findz(int x){
//}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        long long ans=0;
        cin>>n;
        //memset;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
        }
        sort(a[1]+1,a[1]+n+1,cmp);
        for(int u=1;u<=n/2;u++) ans+=a[1][u];
        cout<<ans<<"\n";
    }

    return 0;
}
