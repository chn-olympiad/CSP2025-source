#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopem("seat.out","w",stdout);
    int m,n;
    int h;
    cin>>n>>m;
    int s[1000];
    for(int i=1;i<=n*m;i++){
          cin>>s[i];
    }
    h=s[1];
    int c=0;
    sort(s+1,s+n*m+1);
    for(int i=1;i<=n;i++){
        if(s[i]==h) break;
        if(s[i]!=h) c++;
    }
    int p=m*n-c;
    if(p<=n) cout<<1<<" "<<p;
    else{
        if(p/n%2==1){
            cout<<p/n+1<<" "<<p/n+1;
        }
        else{
                if(p/n==0){
                    cout<<p/n<<" "<<p/n;
                }
            cout<<p/n+1<<" "<<p%n;
        }
    }
    return 0;
}
