#include<bits/stdc++.h>
using namespace std;

long long n,m,x,k,l;
int b[100000];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    x=b[1];
    sort(b+1,b+1+n*m);
    k=0;
    l=1;
    for(int i=1;i<=n*m;i++){
        k++;
        if(k>n){
            k=1;
            l++;
        }
        if(b[i]==x){
            cout<<k<<" "<<l;
            break;
        }

    }
    return 0;


}
