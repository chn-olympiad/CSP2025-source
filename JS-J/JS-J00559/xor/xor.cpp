#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
int a[N];
int b[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int box=0;
    int bo=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            box++;
        }
    }
    if(k==1){
        cout<<box;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]&&b[i]==0&&b[i+1]==0){
                bo++;
                b[i+1]==1;
                b[i]==1;
            }
            if(a[i]==1&&a[i+1]==0&&a[i+2]==1&&b[i]==0&&b[i+1]==0&&b[i+2]==0){
                bo++;
                b[i]==1;
                b[i+1]==1;
                b[i+2]==1;
            }
        }
        cout<<bo-1;
    }
    return 0;
}