#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
   int a,b,n[100],x,y;
    cin>>a;
    cin>>b;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    for(int i=0;i<a;i++){
        x=n[i];
        if(n[i]==b){
            y++;
        }
        if(n[i]-n[i+1]==b){
            y++;
        }
    }
    cout<<y;
    return 0;
}
