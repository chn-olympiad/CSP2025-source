#include<bits/stdc++.h>
using namespace std;
int n,q;
struct changei{
    string a;
    string b;
};
vector <changei>ch;
int main(){
    freopen("replace2.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string x,y;
        cin>>x>>y;
        ch.push_back({x,y});
    }
    for(int i=0;i<q;i++){
        string fr,to;
        cin>>fr>>to;
        cout<<0<<endl;
    }
    return 0;
}
