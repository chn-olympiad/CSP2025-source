#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define pii pair<int,int>
#define st(s) sort(s.begin(),s.end())
#define pb(n) push_back(n)
#define rv(s) reverse(s.begin(),s.end())
#define ins(n) insert(n)
#define vt vector
#define endl "\n"
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,p,l1,re=0;
    cin>>n>>m;
    cin>>p;
    for(int i=1;i<m*n;i++){
        cin>>l1;
        if(l1>p){
            re++;
        }
    }
    //cout<<re<<' '<<n<<endl;
    cout<<(re/n+1)<<' '<<(((re%(2*n))<n)?((re%(2*n))+1):((2*n)-(re%(2*n))));
}
//100 points
