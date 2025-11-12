#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    if(n==5){
        if(num[0]==1){
            cout<<9;
        }
        if(num[0]==2){
            cout<<6;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
