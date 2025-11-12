#include<bits/stdc++.h>
using namespace std;
void testread(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
}
int n,q;
signed main(){
    srand(time(0)^33550336);
    testread();
    cin>>n>>q;
    for(int i=1;i<=q;i++)cout<<rand()<<endl;
    return 0;
}

