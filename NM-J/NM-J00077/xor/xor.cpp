#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long int a,c,s=0,h;
    string b;
    cin>>b;
    long long int x[b.size()];
    for(int i=0;i<b.size();i++){

    if(b[i]>='0'&&b[i]<='9'){
        x[s]=b[i];
        s++;
    }

    }

    for(int i=0;i<s;i++){
    for(int j=0;j<i;j++){
        if(x[j]<x[j+1]){
            h=x[j];
            x[j]=x[j+1];
            x[j+1]=h;
        }
    }
    }
    for(int i=0;i<s;i++){
        cout<<x[i]-48;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
