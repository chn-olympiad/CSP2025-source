#include<bits/stdc++.h>
using namespace std;
int a[100],d,n,m,q,b,e=1,c;
int main(){
    //freopen("number.in","r","stdin")
    //freopen("number.out","w","stdout")
    cin>>n>>m;
    for(int x=1;x<=n*m;x++){
        cin>>a[x];
        if(a[x]>a[1]){
            a[x]=d;
            a[1]=a[x];
            d=a[1];
            b++;
        }
    }
    for(b;b<=m;b++){
        if(b==m){
            e++;
            c=b;
            for(b;b>=1;b--){
                if(b==0){
                    e++;
                    c=b;
                }

        }
    }
            }
cout<<e<<" "<<c;
    return 0;
}
