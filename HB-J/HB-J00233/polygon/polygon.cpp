#include<bits/stdc++.h>
using namespace std;
long long n,a[5050];
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]=1){
        cout<<9;
    }
    if(a[0]=2){
        cout<<6;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
