#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
    long long f,w;
}a[1000];
node mp[100][100];
long long c=0;
bool cmp(node x,node y){
    return x.f>y.f;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long s=n*m;
    for(int i=1;i<=s;i++){
        cin>>a[i].f;
        a[i].w=i;
    }
    sort(a+1,a+1+s,cmp);
    for(int k=1;k<=m;k++){
        if(k%2==1){
            for(int i=1;i<=n;i++){
                c++;
                mp[i][k].f=a[c].f;
                mp[i][k].w=a[c].w;
            }
        }
        else if(k%2==0){
            for(int i=n;i>0;i--){
                c++;
                mp[i][k].f=a[c].f;
                mp[i][k].w=a[c].w;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j].w==1){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
