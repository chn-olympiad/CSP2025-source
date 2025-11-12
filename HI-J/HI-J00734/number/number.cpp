#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long j=0;
    string a;
    string b;
    long long c[1005];
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(isdigit(a[i])){
            b[j]=a[i];
            j++;
        }
    }

    for(int i=0;i<j;i++){
        c[i]=b[i]-'0';
    }
    for(int i=0;i<j;i++){
        if(i==j-1){
            break;
        }
        if(c[i+1]>c[i]){
            swap(c[i],c[i+1]);
        }
    }
    for(int i=0;i<j;i++){
        cout<<c[i];
    }
    return 0;
}
