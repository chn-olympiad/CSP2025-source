#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[15][15];
struct score{
    int sc,id;
}s[1005];
bool cmp(score a,score b){
    return a.sc>b.sc;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;//n行m列
    for(int i=1;i<=n*m;i++){
        cin>>s[i].sc;
        s[i].id=i;
    }
    int k=n*m;
    sort(s+1,s+k+1,cmp);
    int pos;
    for(int i=1;i<=n*m;i++){
        if(s[i].id==1){
            pos=i;
            break;
        }
    }
    int lie=(pos+m-1)/m;
    int hang=pos%n;
    if(lie%2==1){
        if(hang==0) hang=n;
    }else{
        hang=n-hang+1;
    }
    cout<<lie<<' '<<hang;
    return 0;
}
/*2 2
98 99 100 97*/
