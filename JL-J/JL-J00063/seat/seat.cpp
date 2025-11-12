#include<bits/stdc++.h>
using namespace std;
int n,m,me,ansx,ansy;
int idx[101];
void work(){
    int chu=me/n;
    int yu=me%n;
    if(yu==0){ansx=chu;yu=n;chu--;}
    else ansx=chu+1;
    if(chu%2==0){
        ansy=yu;
    }else{
        ansy=n-yu+1;
    }
    return;
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>idx[i];
        if(i==1)me=idx[i];
    }
    sort(idx+1,idx+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(idx[i]==me){
            me=i;
            break;
        }
    }
    work();
    cout<<ansx<<' '<<ansy;
    return 0;
}
