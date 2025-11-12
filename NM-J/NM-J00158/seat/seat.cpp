#include<bits/stdc++.h>
using namespace std;
long long m,n,p,maxn,q,sum,i,number;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>q;
    for(i=2;i<=n*m;i++){
        cin>>p;
        if(p>q)
           maxn+=1;
    }
    for(i=1;i<=m;i++){
            sum=i*n;
            if(i%2==0){
                number=1;
                for(int j=1;j<=n;j++){
                    if(sum-j==maxn){
                        cout<<i<<" "<<number;
                        return 0;
                    }
                       number+=1;
                }
            }
            else{
                number=n;
                for(int j=1;j<=n;j++){
                    if(sum-j==maxn){
                        cout<<i<<" "<<number;
                        return 0;
                    }
                    number-=1;
                }
            }
       }
       return 0;
}
