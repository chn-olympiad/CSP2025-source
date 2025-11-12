#include <bits/stdc++.h>
using namespace std;

string sz[105];
string d[105];
int n,m,r,c,cnt=0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<=n*m-1;i++){
        cin>>sz[i];
    }
    string xiaor=sz[0];
    for(int i=0;i<=n*m-1;i++){
        if(sz[i]>sz[i+1]){
            string aa=sz[i];
            sz[i]=sz[i+1];
            sz[i+1]=aa;
            i++;
        }
        else{
            i++;
        }
    }

    for (int i=0;i<=n*m-1;i++){
        d[i]=sz[i];
    }
    for (int i=0;i<=n*m-1;i++){
        if(d[i]==xiaor){
            cnt=i;
            break;
        }
    }
    int xi=cnt%(2*n);
    c=(cnt+1)/n+(cnt+1)%n;
    if(c%n==1){
        r=cnt%n+1;
    }
    else{
      r=2*n-xi+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
