#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char n;
    long long m[1000000];
    int a=0;
    while(m[a]==0){
        cin>>n;
        m[a]=n;
        a++;
    }
    for(int i=0;i<n;i++){
        int s=0;
        if(m[i]<m[i+1]){
            s=m[i];
            m[i]=m[i+1];
            m[i+1]=s;
        }
    }
    for(int i=0;i<n;i++){
        cout<<m[i];
    }
    return 0;
}
