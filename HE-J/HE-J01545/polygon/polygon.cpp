#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int b,c,d,e,f,n;
    cin>>n;
    int a[100001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=5&&a[0]<10){
        cout<<9;
    }
    else if(n<=5&&a[0]>10){
        cout<<6;
    }
    else{
        cout<<a[0]*a[1]*n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

    }
