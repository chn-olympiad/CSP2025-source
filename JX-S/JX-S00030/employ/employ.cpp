#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,zs;
    cin>>n>>m;
    string s;
    cin>>s;
    int c[n+1];
    for(int i=1;i<=n;i++{
        cin>>c[i];
    }
    zs=n*n;
    for(int i=1;i<=s.size();i++){
        if(x[i-1]<=c[i]&&s.size%2==0){
            zs-=1;
        }
    }
    cout<<zs<<endl;
    return 0;
}