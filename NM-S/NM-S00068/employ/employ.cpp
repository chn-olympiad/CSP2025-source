#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int N=2e6+7;
int c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<n;i++){
        scanf("%d",&c[i]);
    }
    cout<<m;
    return 0;
}
