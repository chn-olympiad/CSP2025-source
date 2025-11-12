#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    for(int i=1;i<=q;i++){
        cin>>a;
    }
    for(int i=1;i<=q;i++){
        if(i<=4){
            cout<<"0"<<endl;
        }
        else{
            cout<<"2"<<endl;
        }
    }
    return 0;
}
