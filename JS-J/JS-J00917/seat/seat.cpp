#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return (a>=b);
}
int n,m,score[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>score[i];
    int x=score[1];
    sort(score+1,score+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(score[i]==x){
            x=i;
            break;
        }
    }
    int xx,yy=ceil((double)x/(double)n);
    if(yy%2){
        if(x%n==0) xx=n;
        else xx=x%n;
    }
    else{
        if(x%n==0) xx=1;
        else xx=n-x%n+1;
    } 
    cout<<yy<<' '<<xx;
    return 0;
}