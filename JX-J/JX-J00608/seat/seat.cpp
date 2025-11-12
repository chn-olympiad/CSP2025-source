#include<bits/stdc++.h>
using namespace std;
struct se{
    int num;
    int scr;
};
int cmp(se a,se b){
    if(a.scr<b.scr)swap(a,b);
}
se a[101];
int main(){
//    freopen("seat.in","r",stdin);
//    freopen("seat.out","w",stdout);
    int n,m,s;cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].scr;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].num==1){
            s=i;
            break;
        }
    }
    int hang,lie;
    if(s%n==0){
        lie=s/n;
        if(lie%2!=0){
            hang=n;
        }else{
            hang=1;
        }
    }else{
        lie=s/n+1;
        if(lie%2!=0){
            hang=s%n;
        }else{
            hang=n-s%n+1;
        }
    }

    cout<<hang<<" "<<lie;
    return 0;
}
