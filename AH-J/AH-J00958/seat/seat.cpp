#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
vector<int> v;
int t;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int a;
        cin>>a;
        if(i==1) t=a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
        if(v[i]==t){
            i++;
            if(i%(2*n)==0){
                cout<<i/n<<" "<<1;
                break;
            }
            if(i%(2*n)>n) cout<<(int)(i/(2*n))*2+2<<" "<<n-i%n+1;
            else cout<<(int)(i/(2*n))*2+1<<" "<<(i-1)%n+1;
            break;
        }
    }
    return 0;
}
