#include<bits/stdc++.h>
using namespace std;
int n,m,a,id=1;
int c=1,r=1;
int main(){
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=m*n;i>=2;i--){
        int t;
        cin>>t;
        if(t>a) id++;
    }
    int flag=1;
    for(int i=1;i<id;i++){
        if((r==n&&flag==1)||(r==1&&flag==-1))
            c++,flag*=-1;
        else r+=flag;
    }
    cout<<c<<" "<<r;
    return 0;
}
