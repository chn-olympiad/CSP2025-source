#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin)
    freopen("seat.out","w",stdout)
    int n,m,a;
    cin>>n>>m;
    int s[n*m];
    for(int i=0;i<n*m;i++){
        cin>>s[i];
    }
    for(int i=0;i<n*m;i++){
        for(int j=0;j<i;j++){
            if(s[j]<s[j+1]){
               a=s[j];
               s[j]=s[j+1];
               s[j+1]=a;
            }
        }
    }

    return 0;
}
