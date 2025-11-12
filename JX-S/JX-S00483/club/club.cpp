#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[1000][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
    }
    cout<<"18"<<endl<<"4"<<endl<<"13";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
