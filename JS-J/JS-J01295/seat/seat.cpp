#include<bits/stdc++.h>
using namespace std;
int n,m;
int sit[1100]={0};
int res[15][15]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int score,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sit[i];
    }
    score=sit[1];

    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(sit[j]>sit[i]){
                swap(sit[j],sit[i]);
            }
        }
    }
    int val;
    for(int i=1;i<=n*m;i++){
        if(sit[i]==score){
            val=i;
            break;
        }
    }

    int d=val%n;
    if(d==0){
        d=n;
    }
    c=(val-d)/n+1;

    if(c%2==1){
        r=val%(2*n);
        if(r==0){
            r=n;
        }
    }else{
        if(val<=2*n){
            r=n-(val-n)+1;
        }else{
            r=n-(val-n*(c-1))+1;
        }
    }

    cout<<c<<" "<<r;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
