#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,score;
};
node a[105];
bool cmp(node x,node y){
    return x.score>y.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int k,ansn,ansm;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            k=i;
        }
    }
    ansm=(k-1)/n+1;
    if(ansm%2==0){
        ansn=n+1-(k%n);
        if(ansn==n+1){
            ansn=1;
        }
    }else{
        ansn=k%n;
        if(ansn==0){
            ansn=n;
        }
    }
    cout<<ansm<<' '<<ansn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
