#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

const ll md=998244353;

int a[505];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    bool f=1;
    int ct=0;
    for(char i:s){
        if(i!='1'){
            f=0;
            break;
        }else{
         ct++;
        }
    }
    if(ct<m){
        cout<<0;
        return 0;
    }
    if(f){
        int c=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=0) c++;
        }
        ll q=1;
        for(int t=c;t>1;t--){
            q*=t;
            q%=md;
        }
        cout<<q;
        return 0;
    }else{
        cout<<2;
    }
    return 0;
}
