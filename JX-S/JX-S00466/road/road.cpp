#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int money=0;
struct s{
    int r1,r2,mo;
}a[10000001];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
        cin>>a[i].r1>>a[i].r2>>a[i].mo;
}
int mini;
for(int i=1;i<=n-1;i++){
    for(int y=i+1;y<=n;y++){
        mini=1000000001;
        for(int o=1;o<=m;o++){
            if((a[o].r1==i&&a[o].r2==y)||(a[o].r2==i&&a[o].r1==y)){
                mini=min(a[o].mo,mini);
            }
        }
        money+=mini;
    }
}
cout<<money;
return 0;
}
