#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    int score,NO;
    bool is_xiaoR;
};
int n,m;
node a[105];
bool cmp(node a,node b){
    return a.score>b.score;
}
long long ans[130]={};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    a[0].is_xiaoR=1;
    for(int i=0;i<n*m;i++){
        cin>>a[i].score;
    }
    sort(a,a+n*m,cmp);
    for(int i=1;i<n*m;i++){
        if(a[i].is_xiaoR){
            cout<<(i-1)/n+1<<" "<<(((i-1)/n+1)%2==1?i%n+1:n-i%n);
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}/*

*/
