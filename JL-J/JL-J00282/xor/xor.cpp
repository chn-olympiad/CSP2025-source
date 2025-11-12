#include<bits/stdc++.h>
using namespace std;
int a,n,m,x=-99,y=0;
string s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a==m){
            y++;
        }
        else if(x==m){
            x=-99;
            y++;
        }
        else if(x==-99){
            x=a;
        }
        else{
            x^=a;
        }
    }
    cout<<y;
    return 0;
}
