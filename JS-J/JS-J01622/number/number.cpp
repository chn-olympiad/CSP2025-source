#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[1000001];
    int b[1000001];
    int ct=0;
    for(long i=0;i<1000001;i++){
        a[i]='a';
        b[i]=0;
    }
    cin>>a;
    for(long i=0;i<1000001;i++){
        if('0'<=a[i] and '9'>=a[i]){
            b[ct]=a[i]-48;
            ct++;
        }
    }
    b[ct]=-1;
    for(int i=9;i>=0;i--){
        for(long j=0;j<1000001;j++){
            if(b[j]==-1)break;
            if(b[j]==i)cout<<b[j];
        }
    }
    return 0;
}
