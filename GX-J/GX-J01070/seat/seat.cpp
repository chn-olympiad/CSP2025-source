#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,m1,n1,k;
    cin>>n>>m;
    int p=n*m;
    int a[100010];
    int cou=1;
    for(int i=0;i<p;i++){
        cin>>a[i];
    }
    for(int c=1;c<p;c++){
        if(a[0]>a[c]){
            continue;
        }
        else{
            cou++;
        }
    }
    k=cou%n;
    if(k!=0){
            m1=cou/n+1;
            if(m1%2!=0){
                n1=k;
            }
            else{
                n1=n+1-k;
            }
    }
    else{
        m1=cou/n;
        if(m1%2!=0){
                n1=n;
            }
            else{
                n1=1;
            }
    }
    cout<<m1<<n1;
    return 0;
}
