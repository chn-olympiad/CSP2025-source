#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ss{
    int id,d;
}zw[105];
bool cmp(ss a,ss b){
	return a.d>b.d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>zw[i].d;
        zw[i].id=i;
    }
    sort(zw+1,zw+n*m+1,cmp);
    int pm;
    for(int i=1;i<=n*m;i++){
        if(zw[i].id==1){
            pm=i;
            break;
        }
    }
    int l=pm/n,h=pm%n;
    if(h==0){
        h=n;
    }else{
        l++;
    }
    if(l%2==0){
        h=n-h+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
