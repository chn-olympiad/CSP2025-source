#include <iostream>
#include <cstdio>
using namespace std;
int n,m,c[505],t;
long long ans;
bool s[505],vis[505],vis1[505][505];
//bool mem[501][501],memu[501][501][501];
long long f1(int x,int y){//x*x-1*x-2*...*y+1*y
    long long t=1;
    for(int i=y;i<=x;i++){t*=i;t%=998244353;}
    return t;
}
void f(int fail,int suc){
    int day=fail+suc+1;
    if(suc>=m){
        //cout<<"ans+1="<<ans+1<<endl;
        ans+=f1(n-day+1,2);
        ans%=998244353;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]+vis1[day][i])continue;
        vis[i]=1;
        if(s[day]&&c[i]>fail){
            //vis1[day][i]=1;
            f(fail,suc+1);
        }
        else {
            f(fail+1,suc);
        }
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    while(getchar()!='\n');
    for(int i=1;i<=n;i++){
        bool t1=getchar()-'0';
        t+=t1;
        s[i]=t1;
        //cout<<"\n>s\["<<i<<"\]="<<s[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        //cout<<"\n>c\["<<i<<"\]="<<c[i]<<endl;
    }
    f(0,0);
    cout<<ans;
    return 0;
}
