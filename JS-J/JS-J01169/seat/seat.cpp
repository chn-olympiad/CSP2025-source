#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n,m;
struct node{
    int a,id;
}s[110];
bool cmp(node x,node y){
    return x.a>y.a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        if(i==1)s[i].id=1;
        cin>>s[i].a;
    }
    int x=1,y=1,cs=1;
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){

        if(s[i].id==1){
            cout<<x<<' '<<y;
            break;
        }
        y+=cs;
       // cout<<x<<' '<<y<<endl;
        if(y>n){
            y=n;
            x++;
            cs=-cs;
        }
        if(y<1){
            y=1;
            x++;
            cs=-cs;
        }

    }
    return 0;
}
