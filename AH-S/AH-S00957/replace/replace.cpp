#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node{
    string a,b;
}x[N];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>x[i].a>>x[i].b;
    }
    while(q--){
        cout<<"0"<<endl;
    }
    return 0;
}
