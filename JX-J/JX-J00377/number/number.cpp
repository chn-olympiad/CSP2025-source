#include<bits/stdc++.h>
using namespace std;
char shu[1000100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdin);
    string n;
    cin>>n;
    long long k=0;
    for(long long i=0;i<n.size();i++){
        if(n[i]>='0' and n[i]<='9'){
            shu[k]=n[i];
            k++;
        }
    }
    for(long long  i=0;i<=k;i++){
        for(long long j=0;j<=k;j++){
            if(shu[j]<shu[j+1]){
                swap(shu[j],shu[j+1]);
            }
        }
    }
    for(long long i=0;i<k;i++){
        cout<<shu[i];
    }
    return 0;
}
//123
