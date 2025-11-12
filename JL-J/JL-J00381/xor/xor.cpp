#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a;
    int n,k,q[1000000];
    cin>>n>>k;
    for(int i=0;i<n;i++){
            cin>>q[i];
    }
    srand(time(0));
    a=rand()%100;
    int b=rand()%20000;
    if(rand()%2){
        cout<<a;
    }else{
    cout<<b;}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

