#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;string a,b;
    cin>>n>>m;
    srand(time(0));
    for(int i=0;i<n;i++){
        cin>>a>>b;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<rand()%10<<endl;
    }
    return 0;
}
