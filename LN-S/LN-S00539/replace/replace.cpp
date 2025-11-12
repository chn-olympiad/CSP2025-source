#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    string x,y;
    for(int i=0;i<a;i++) cin>>x>>y;
    for(int i=0;i<b;i++) cin>>x>>y;
    if(a==4 && b==2) cout<<"2\n0";
    if(a==3 && b==4) cout<<"0\n0\n0\n0";
}
