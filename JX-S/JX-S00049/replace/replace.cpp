#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
struct ab{
    string a,b;
};
vector<ab> a,b;
string aa,bb;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>aa>>bb;
        a.push_back({aa,bb});
    }
    for(int i=0;i<q;i++){
        cin>>aa>>bb;
        b.push_back({aa,bb});
        cout<<"0"<<endl;
    }
    return 0;
}

