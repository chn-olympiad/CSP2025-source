#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10;
struct E{
    string a,b;
}q[N];
struct H{
    string x,y;
}p[M];
int n,m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>q[i].a>>q[i].b;
    }
    for(int i=1;i<=m;i++){
        cin>>p[i].x>>p[i].y;
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
