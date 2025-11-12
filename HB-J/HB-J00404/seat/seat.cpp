#include<bits/stdc++.h>
using namespace std;
long long n,m,g,x=1,y=1,t;
long long gra[10001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>g;
    gra[1]=g;
    for(int i=2;i<=n*m;i++){
        cin>>gra[i];
    }
    sort(gra,gra+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(gra[i]==g) t=i;
    }
    for(int i=1;i<=n*m;i++){

        if(y%2==1&&i!=1){
            x++;
        }else if(y%2==0&&i!=1){
            x--;
        }
        if(x==n+1&&y%2==1){
            x=n;
            y++;
        }else if(x==0&&y%2==0){
            x=1;
            y++;
        }
        if(i==t+1){
            cout<<y<<" "<<x<<endl;
        }

    }
    return 0;
}
