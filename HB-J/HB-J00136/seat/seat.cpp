#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int u=n*m;
    for(int i=1;i<=u;i++){
        cin>>a[i];
    }
    int o=a[1],t=0;
    sort(a+1,a+1+u,cmp);
    for(int i=1;i<=u;i++){
        if(a[i]==o){
            t=i;
            break;
        }
    }
    int h=t/n,l=t%n;
    if(t%n!=0){
        h++;
    }
   if(l==0){
        if(h%2==0){
            l=1;
        }else{
            l=n;
        }
   }else{
       if(h%2==0){
            l=n+1-l;
       }
   }
    cout<<h<<" "<<l;
    return 0;
}
