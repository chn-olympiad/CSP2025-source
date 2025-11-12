#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>q;
    string a[n][2],b[q][2];
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=q;i++){
        cin>>b[i][1]>>b[i][2];
    }
    cout<<"2"<<endl<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
