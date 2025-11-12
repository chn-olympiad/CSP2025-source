#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e5+9;
int n,q;
pair<string,string> S[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string S1,S2;
        S[i]={S1,S2};
    }
    for(int p=1;p<=q;p++){
        string T1,T2;
        cin>>T1>>T2;
        if(T1.size()!=T2.size()){
            cout<<"0"<<endl;
            continue;
        }
        int cnt=0;
        cout<<cnt<<endl;
    }
}
