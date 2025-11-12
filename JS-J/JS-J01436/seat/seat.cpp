#include <bits/stdc++.h>
using namespace std;
const int maxn=197;
int n,m;
int st[maxn],R,id;

bool cmp(int a,int b){
    return a>b;
    }
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>st[i];
    }
    R=st[1];
    sort(st+1,st+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(st[i]==R){
            id=i;
            break;
        }
    }
    id-=1;
    int y=id/n;
    cout<<id/n+1<<" ";
    if(y%2==0){
        cout<<id%n+1;
    }else{
        cout<<n-(id%n);
    }

    fclose(stdin);
    fclose(stdout);

   return 0;
}
