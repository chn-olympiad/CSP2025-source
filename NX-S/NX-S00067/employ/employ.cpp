#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
string s;
int c[1000];
int cb[1000];
long long p=1,p2;
int main(){
    freopen("employ3.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    cin>>s;
    int z=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        cb[c[i]]+=1;
    }
    cout<<z<<endl;
    for(int i=1;i<=n-cb[0];i++){
        p=p*i;
        p=p%N;
    }


    cout<<p;

    return 0;
}

