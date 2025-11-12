#include<bits/stdc++.h>
using namespace std;
int n,m,b[101];
void oo(){
    for(int i=1;i<n*m;i++){
        bool fla=false;
        for(int i=1;i<n*m;i++){
            if(b[i+1]>=b[i]){
                swap(b[i],b[i+1]);
                fla=true;
            }
        }
        if(!fla) return ;
    }

}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int k=b[1];
    oo();
    for(int i=1;i<=n*m;i++){
        if(b[i]==k) {
            k=i;
            break;
        }
    }
    if(k%n==0){
        if(k/n%2==0){
            cout<<k/n<<" "<<1;
        }
        else{
            cout<<k/n<<" "<<n;
        }
    }
    else{
        cout<<k/n+1<<" "<<k%n;
    }
    return 0;
}
