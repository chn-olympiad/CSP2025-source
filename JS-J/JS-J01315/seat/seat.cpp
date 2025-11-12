#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int sc[150]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l,r;
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=l;i++){
        cin>>sc[i];
    }
    r=sc[1];
    sort(sc+1,sc+l+1,cmp);
    int p=0;
    for(int i=1;i<=l;i++){
        if(sc[i]==r){
            p=i;
            break;
        }
    }
    int hang,lie;
    lie=(p-1)/n+1;
    if(lie%2==0){
        int yy=p%n;
        if(yy==0)hang=1;
        else hang=n-yy+1;
    }else{
        int yy=p%n;
        if(yy==0)hang=n;
        else hang=yy;
    }
    cout<<lie<<" "<<hang;
    return 0;
}
