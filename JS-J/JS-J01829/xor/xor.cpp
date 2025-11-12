#include<bits/stdc++.h>
using namespace std;
int a[500000],b[500000]={-2};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            s++;
            continue;
        }
        else if(i!=0&&b[i-1]!=-1){
            int x=a[i]^b[i-1];
            if(x==k){
                s++;
                b[i-1]=-1;
                continue;
            }
        }
        if(b[i-1]==-1)b[i]=a[i];
        else b[i]=b[i-1]^a[i];
    }
    cout<<s;
    return 0;
}
