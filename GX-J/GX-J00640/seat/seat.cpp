#include<bits/stdc++.h>
using namespace std;
int n,m,sum,l;
int c[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n*m;i++){
        if(c[i]>c[0]){
            sum++;
        }
    }
    sum++;
    if(sum%n==0){
        l=sum/n;
    }else{

        l=sum/n+1;
    }
    cout<<l<<" ";
    if(l%2==1){
        cout<<sum-(l-1)*n;
    }else{
        cout<<n-((sum-(l-1)*n)-1);
    }
    return 0;
}
