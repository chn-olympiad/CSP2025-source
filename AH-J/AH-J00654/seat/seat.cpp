#include<bits/stdc++.h>
using namespace std;
struct node{
    int s,num;
}a[105];
bool cmp(node a,node b){
    return a.s>b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[(i-1)*n+j].s;
            a[(i-1)*n+j].num=(i-1)*n+j;
        }
    }
    int ans1=0,ans2=0;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        ans1++;
        bool f=0;
        if(ans1%2==0){
            ans2=n+1;
            f=1;
        }else{
            ans2=0;
        }
        for(int j=1;j<=n;j++){
            int sum=(i-1)*n+j;
            if(f==1){
                ans2--;
            }else{
                ans2++;
            }
            if(a[sum].num==1){
                cout<<ans1<<" "<<ans2;
            }
        }
    }

    return 0;
}
