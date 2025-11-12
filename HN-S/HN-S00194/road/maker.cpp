#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int kmaxn=1e4+50,kmaxm=1e6+10,kl=11,Ma=1e9;
int n=1e4,m=1e6,k=10;
int Pw(){return 1ll*rand()*rand()%Ma+1;}
int Pu(){return 1ll*rand()*rand()%n+1;}
signed main(){
    freopen("road.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);srand(time(0));
    cout<<n<<" "<<m<<" "<<k<<"\n";
    while(m--){
        cout<<Pu()<<" "<<Pu()<<" "<<Pw()<<"\n";
    }
    while(k--){
        for(int i=1;i<=n+1;i++)cout<<(rand()%2?Ma:0)<<" ";
        cout<<"\n";
    }
    return 0;
}