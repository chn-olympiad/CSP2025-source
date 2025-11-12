#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int kmaxn=2e5+10;
int n=2e5,q=2e5,T=25;
char R(){return char(rand()%2+'a');}
string D(){
    string x="";
    for(int i=0;i<T;i++)x+=R();
    return x;
}
signed main(){
    freopen("replace.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);srand(time(0));
    cout<<n<<" "<<q<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=0;j<T;j++)cout<<R();cout<<" ";
        for(int j=0;j<T;j++)cout<<R();
        cout<<"\n";
    }
    for(int i=1;i<=q;i++){
        string A=D(),B=D();
        while(A==B){
            A=D();B=D();
        }
        cout<<A<<" "<<B<<"\n";
    }
}