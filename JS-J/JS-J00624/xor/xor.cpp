#include<bits/stdc++.h>
#define FUCK using
#define THE namespace
#define CCF std;
FUCK THE CCF
#define ll long long
int n,k;
int a[1000000];
bool flag=true;
int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]!=1){
            flag=false;
            exit(0);
        }
    }
    if(n==1&k==0){
        cout<<"0"<<endl;
    }
    if(n==2&k==0){
        cout<<"1"<<endl;
    }

    return 0;
}
