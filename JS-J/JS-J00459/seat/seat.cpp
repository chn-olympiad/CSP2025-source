#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,cheng=0,pai=0,lie=0,hang=0;
ll a[100009];
void qul(){
    if(pai%n==0){
        lie=pai/n;
    }else{
        lie=pai/n+1;
    }
}
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    cin>>a[1];
    cheng=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==cheng){
            pai=i;
        }
    }
    qul();
    if(lie%2==0){
        if(pai%n==0){
            hang=1;
        }else{
            hang=n+1-(pai%n);
        }
    }else{
        if(pai%n==0){
            hang=n;
        }else{
            hang=pai%n;
        }
    }
    cout<<lie<<" "<<hang;
    return 0;
}
