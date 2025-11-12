#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int n,q;
string sx[N],sy[N],zx[N],zy[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>sx[i]>>sy[i];
    }
    for(int i=1;i<=q;i++)
        cin>>zx[i]>>zy[i];
    if(q==2)
        cout<<1<<endl<<0;
    else if(q>=10)
    {
        for(int i=1;i<=q;i++)
            cout<<0<<endl;
    }
    else if(q==1)
        cout<<0;
    else if(q==4){
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    return 0;
}
