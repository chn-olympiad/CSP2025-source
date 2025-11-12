#include <bits/stdc++.h>
using namespace std;
bool ifpolygon(int x,int bian[]){
    int maxn=0;
    int tnt=0;
    for(int i=1;i<=x;i++){
        tnt+=bian[i];
        maxn=max(maxn,bian[i]);
    }
    if(tnt>maxn*2&&x>=3)return 1;
    return 0;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    long long tnt=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    return 0;
}
