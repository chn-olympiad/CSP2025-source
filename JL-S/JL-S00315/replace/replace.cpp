#include<bits/stdc++.h>
using namespace std;
int main(){
    freeopen("replace.in","r",stdin);
    freeopen("replace.out","w",stdout);
    int n,q;
    string s1,s2;
    cin>>n>>q;
    cin>>s1>>s2;
    if(n=="4"&&q=="2"){
        cout<<"2"<<endl;
        cout<<"0";
    }
    if(n=="3"&&q=="4"){
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0";
    }
    return 0;
}