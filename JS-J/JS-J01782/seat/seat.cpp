#include<bits/stdc++.h>
#define N 200
using namespace std;
int n,m,cnt;
struct node{
    int num,val;
}a[N];
bool cmp(node a,node b){
    return a.val>b.val;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].val;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                if(a[cnt].num==1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j;j--){
                cnt++;
                if(a[cnt].num==1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
