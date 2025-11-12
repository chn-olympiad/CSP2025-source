#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int cj[100001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=m*n;i++)cin >> cj[i];
    r=cj[1];
    for(int i=1;i<=m*n;i++){
        for(int j=i+1;j<=m*n;j++){
            if(cj[i]<cj[j]){
                int t=cj[i];
                cj[i]=cj[j];
                cj[j]=t;
            }
        }
    }
    int pm,lie,hang;
    for(int i=1;i<=m*n;i++)if(cj[i]==r)pm=i;
    if(pm%n==0)lie=pm/n;
    else lie=pm/n+1;
    cout<<lie<<" ";
    while(pm>m)pm-=m;
    if(lie%2==1)cout<<pm;
    else cout<<m-pm+1;
    return 0;
}
