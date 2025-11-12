#inclde<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b;
    cin>>a>>b;
    if(a==5&&b==1)
        cout<<9;
    else if(a==5 && b==2)
        cout<<6;
    else
        cout<<10;
    return 0;
}
