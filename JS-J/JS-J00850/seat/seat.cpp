#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int b,int c){
    return b>c;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num,v;
    cin>>n>>m;
    num=n*m;
    int x;
    cin>>x;
    a[0]=x;
    for(int i=1;i<num;i++){
        int y;
        cin>>y;
        a[i]=y;
    }
    sort(a,a+num,cmp);
    for(int i=0;i<num;i++){
        if(a[i]==x){
            v=i+1;
            break;
        }
    }
    int j,k;
    if(v%n==0){
        j=v/n;
    }
    else{
        j=v/n+1;
    }
    if((v%n==0 || v%n==1) && (v%(n*2)!=0 && v%(n*2)!=1)){
        k=n;
    }
    else{
        if(v%(n*2)<n){
            k=v%n;
        }
        else{
            k=n-v%(n*2)+1;
            k=k%n;
        }
    }
    cout<<j<<" "<<k;
    return 0;
}
