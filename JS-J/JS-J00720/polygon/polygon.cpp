#include<bits/stdc++.h>
using namespace std;
int n,c[5005],xl[5005],s=0,fa[2][10000000],l=0;
vector<int> x;
void f(int sl,int q,int e){
    if(sl>=3){
        int h,maxx=xl[e];
        for(int i=q;i<=e;i++)h+=xl[i];
        if(h>2*maxx){
            s++;
        }
    }
    for(int i=e+1;i<=n;i++){
        x.push_back(xl[i]);
        f(sl+i-e,q,i);
        x.pop_back();
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c,c+n-1);
    f(0,1,0);
    /*for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(fa[0][i]==fa[0][j]&&fa[1][i]==fa[1][j])fa[0][j]=0;
        }
    }
    for(int i=0;i<l;i++)if(fa[0][i]!=0)s++;*/
    cout<<s;
    return 0;
}
