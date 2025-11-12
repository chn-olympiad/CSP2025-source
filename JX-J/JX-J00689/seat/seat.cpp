#include<bits/stdc++.h>
using namespace std;
int a[1000010];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int mn=n*m;
    for(int i=1;i<=mn;i++){
        cin>>a[i];
    }
    int xiaor=a[1];
    sort(a+1,a+mn+1);
    int pm;
    for(int i=1;i<=mn;i++){
        if(a[i]==xiaor){
            pm=mn-i+1;
            break;
        }
    }
    int c,r;
    c=pm/m;
    if(pm%m!=0){
        c++;
    }
    pm=pm-(c-1)*m;
    if(c%2==0){
        r=m-pm+1;
    }
    else if(c%2!=0){
        r=pm;
    }
    cout<<c<<" "<<r;
    return 0;
}
