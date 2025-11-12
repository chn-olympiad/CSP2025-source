#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10;

int n,m,a;
int s=1,l;

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a;
        if(i==1){
            l=a;
        }else{
            if(a>l){
                s++;
            }
        }
    }

    if(s%n==0){
        if((s/n)%2==1){
            cout<<s/n<<" "<<n;
        }else{
            cout<<s/n<<" "<<1;
        }
    }else{
        if((s/n)%2==1){
            cout<<s/n+1<<" "<<n-(s/n)+1;
        }else{
            cout<<s/n+1<<" "<<s%n;
        }
    }

    return 0;
}
