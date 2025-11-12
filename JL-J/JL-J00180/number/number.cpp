#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    long long n=0,a=1,d=1;
    int b[10000];
    cin>>c;
    for(int i=0;i<=c.size;i++){
        if(c[i]==1||c[i]==2||c[i]==3||c[i]==4||c[i]==5|c[i]==6||c[i]==7||c[i]==8||c[i]==9||c[i]==0){
            b[i]=c[i];
        }
    }
    for(int i=1;i<=b.size;i++){
        for(int j=1;j<=b.size;j++){
            if(b[i]>b[i+1]){
                n=b[i];
                b[i]=b[i+1];
                b[i+1]=n;
            }
        }
    }
    for(int i=b.size;i>=0;i--){
        cout<<b[i];
    }

}

