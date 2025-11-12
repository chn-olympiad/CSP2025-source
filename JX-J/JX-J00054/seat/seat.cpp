#include<bits/stdc++.h>
using namespace std;
int s[300];
int n,m,t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&s[i]);
    }
    int t=s[1];
    sort(s+1,s+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(s[i]==t){
            int id=(i+n-1)/n;
            if(id%2==1){
                cout<<id<<" "<<i-((id-1)*n);
                return 0;
            }
            else if(id%2==0){
                cout<<id<<" "<<n+1-(i-((id-1)*n));
                return 0;
            }
        }
    }
    return 0;
}
