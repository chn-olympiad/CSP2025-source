#include<bits/stdc++.h>
using namespace std;
int n,m,q,w,now;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    q=n*m;
    now=q;
    int a[q+1]={0};
    for(int i=1;i<=q;i++){
        cin>>a[i];
    }
    w=a[1];
    sort(a+1,a+1+q);
    int x=1;
    for(int y=1;y<=m;y++){
        int b=y%2;
        if(x<1)x=1;
        if(x>n)x=n;
        for(;x>=1&&x<=n;now--){
            //cout<<now<<' '<<a[now]<<' '<<y<<' '<<x<<'\n';
            if(a[now]==w){
                cout<<y<<" "<<x;
                return 0;
            }
            if(b)x++;
            else x--;
        }
    }
    //cout<<"error";
    return 0;
}
//luogu:1073546
//time:20251101 09:40
//rp++
//rp++
//rp++
//rp++
//rp++
