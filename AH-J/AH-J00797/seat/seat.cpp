#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    int i,n,m,r,wei,a[110];
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(i=1;i<=(n*m);i++){
        if(a[i]==r){
            wei=i;
            break;
        }
    }
    int var=wei+n-1,l=var/n,h;
    if(l%2){
        h=var%n+1;
    }else{
        h=n-(var%n);
    }
    cout<<l<<" "<<h<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
