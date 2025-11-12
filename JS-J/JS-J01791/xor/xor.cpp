#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
    cin>>n>>k;
    for(int i=1;i=n;i++){
        cin>>a[i];
        if(a[i]>1){
            cout<<0;
        }else{
            cout<<1;
        }
        return 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
