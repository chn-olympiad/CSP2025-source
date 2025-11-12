#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k;
int a[N];
int fl=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            fl+=1;
        }
    }if(fl!=0&&k==0)cout<<fl;
    else if(k==0)cout<<"0";
    else cout<<"shangshanruoshui";
    return 0;
}
