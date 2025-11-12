#include "bits/stdc++.h"
using namespace std;

long long n,m;
long long score[2005];
long long R,Rid;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>score[i];
    }
    R=score[1];
    stable_sort(score+1,score+n*m+1);
    for(int i=1;i<=n*m;i++){
        //cout<<score[i]<<"-";
        if(score[i]==R){
            Rid=i;
            break;
        }
    }
    Rid=n*m-Rid+1;
    //cout<<Rid<<" "<<R<<endl;
    if(Rid%n==0){
        cout<<Rid/n<<" "<<(((Rid/n)%2)?n:1);
    }else{
        cout<<Rid/n+1<<" "<<((Rid/n+1)%2?Rid%n:n-Rid%n+1);
    }
    return 0;
}
