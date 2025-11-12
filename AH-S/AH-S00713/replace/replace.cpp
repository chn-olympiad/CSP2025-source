#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    string li1,li2;
    cin>>n>>m;
    struct e{
        string a;
        string b;
    };
    vector<e> q;
    string t1,t2;
    for(int i=0;i<n;i++){
        cin>>t1>>t2;
        q.push_back({t1,t2});
    }
    for(int i=0;i<m;i++){
        int sum=0;
        cin>>li1>>li2;
        for(int j=0;j<n;j++){
            if(find(&li1,&li1+li1.size(),q[j].a)){
                cout<<find(&li1,&li1+li1.size(),q[j].a)<<' '<<q[j].a<<endl;
            }
        }
    }
    return 0;
}
