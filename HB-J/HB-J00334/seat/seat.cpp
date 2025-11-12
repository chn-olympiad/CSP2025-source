#include<bits/stdc++.h>
using namespace std;
int m,n;
int t[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
         cin>>t[i];
    }
    int p=t[1],pk;
    sort(t+1,t+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(t[i]==p){pk=i;break;}
    }
    int l=pk/n;
    if(pk%n) l++;
    if(l%2==1){
        if(pk%n!=0){
            cout<<l<<' '<<pk%n;
        }else{
            cout<<l<<' '<<n;
        }
    }else{
        int kkk=pk%n;
        if(kkk==0) kkk=n;
        cout<<l<<' '<<n+1-kkk;
    }
    return 0;
}
