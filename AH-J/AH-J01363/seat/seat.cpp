#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int num;
    int score;
}a[110];
bool cmp(node x,node y){
    return x.score>y.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].num=i;
    }int ans=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].num==1){
            ans=i;
        }
    }int flag=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                flag++;
                if(flag==ans){
                    cout<<i<<" "<<j;
                    exit(0);
                }
            }
        }else{
            for(int j=1;j<=n;j++){
                flag++;
                if(flag==ans){
                    cout<<i<<" "<<j;
                    exit(0);
                }
            }
        }

    }
    return 0;
}
