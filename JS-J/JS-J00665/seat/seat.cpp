#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[105][105];
int score[10005];
int t;
int pos=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int r_score;
    cin>>r_score;
    for(int i = 2;i<=n*m;i++){
        cin>>t;
        pos+=(t>r_score);
    }
    int y;
    int x=pos/n+(pos%n>0);
    if(x%2==0)y=n-(pos-(x-1)*n)+1;
    else y=pos-(x-1)*n;
    printf("%d %d",x,y);
    return 0;
}
