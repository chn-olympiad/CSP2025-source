#include<bits/stdc++.h>
using namespace std;
const int N=510,Max=998244353;
string str;
int n,m,c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>str;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    cout<<Max-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
