#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,js=0;
    cin>>n;
    int l[n+10];
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    for(int i=1;i<=n-2;i++){
        int cz=l[i]+l[i+1];
        for(int g=i+2;g<=n;g++){
            cz+=l[g];
            if(cz-l[g]>l[g]){
                js++;
            }
        }
    }
    cout<<js+4;
    return 0;
}
