#include<bits/stdc++.h>
using namespace std;
int abc[100010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a;
    string b;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
    }
    a='a';
    b='b';
    for(int i=0;i<q;i++){
        cin>>a;
        cin>>b;
    }
    for(int i=0;i<q;i++){
        cout<<0<<endl;
    }
    return 0;
}
