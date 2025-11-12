#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,x[10000],c,s,z,y,g;
int main(){
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
     cin>>n>>m;
     for(i=1;i<=n*m;i++){
        cin>>x[i];
     }
     c=x[1];
     sort(x+1,x+1+n*m,greater<int>());
     for(i=1;i<=n*m;i++){
        if(c==x[i]){
            s=i;
            break;
        }
     }
     for(i=1;i<=m;i+=2){
        if(i==1){
            if(s>=1&&s<=i*n){
                g=1;
                break;
            }
        }
        else{
            if(s>=i*n-n+1&&s<=i*n){
                g=1;
                break;
            }
        }
     }
     if(g==0){
        if(s%n==0){
            y=s/n;
            z=1;
        }
        else {y=s/n+1;z=n-(s%n)+1;}
        cout<<y<<" "<<z;
        return 0;
     }
     else if(g==1){
        if(s%n==0){
            y=s/n;
            z=n;
        }
        else {y=s/n+1;z=s%n;}
        cout<<y<<" "<<z;
        return 0;
     }
     return 0;
}
