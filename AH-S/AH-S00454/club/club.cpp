#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,a[N][4];
int id;
int fib(int i){
    int id=0;
    for(int j=1;j<=3;j++){
        if(a[i][j]>a[i][id])id=j;
    }
    return id;
}
int seb(int i){
    int id1=0,id2=0;
    for(int j=1;j<=3;j++){
        if(a[i][j]>a[i][id1]){
            id2=id1,id1=j;
        }
        else if(a[i][j]>a[i][id2])id2=j;
    }
    return id2;
}
int fis(int i){
    int id=0;
    for(int j=1;j<=3;j++){
        if(a[i][j]<a[i][id])id=j;
    }
    return id;
}
bool cmp1(int x,int y){
    int resx=0,resy=0,id=1;
    resx=((id==fib(x))?(a[x][fib(x)]-a[x][seb(x)]):(a[x][seb(x)]-a[x][fis(x)]));
    resy=((id==fib(y))?(a[y][fib(y)]-a[y][seb(y)]):(a[y][seb(y)]-a[y][fis(y)]));
    return resx>resy;
}
bool cmp2(int x,int y){
    int resx=0,resy=0,id=2;
    resx=((id==fib(x))?(a[x][fib(x)]-a[x][seb(x)]):(a[x][seb(x)]-a[x][fis(x)]));
    resy=((id==fib(y))?(a[y][fib(y)]-a[y][seb(y)]):(a[y][seb(y)]-a[y][fis(y)]));
    return resx>resy;
}
bool cmp3(int x,int y){
    int resx=0,resy=0,id=3;
    resx=((id==fib(x))?(a[x][fib(x)]-a[x][seb(x)]):(a[x][seb(x)]-a[x][fis(x)]));
    resy=((id==fib(y))?(a[y][fib(y)]-a[y][seb(y)]):(a[y][seb(y)]-a[y][fis(y)]));
    return resx>resy;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int n;
        vector<int>v[4];
        ll ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int max_id=0;
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
                if(a[i][j]>a[i][max_id]){
                    max_id=j;
                }
            }
            v[max_id].push_back(i);
        }
        sort(v[1].begin(),v[1].end(),cmp1);sort(v[2].begin(),v[2].end(),cmp2);sort(v[3].begin(),v[3].end(),cmp3);
        for(int k=1;k<=4;k++)
            for(int i=1;i<=3;i++){
                while(v[i].size()>n/2){
                    int tmp=*(v[i].end()-1);
                    v[i].erase(v[i].end()-1);
                    int id=seb(tmp);
                    if(i==id)id=fis(tmp);
                    v[id].push_back(tmp);
                    if(id==1)sort(v[id].begin(),v[id].end(),cmp1);
                    if(id==2)sort(v[id].begin(),v[id].end(),cmp2);
                    if(id==3)sort(v[id].begin(),v[id].end(),cmp3);
                }
            }
        for(int i=1;i<=3;i++){
            for(auto s:v[i]){
                ans+=a[s][i];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
