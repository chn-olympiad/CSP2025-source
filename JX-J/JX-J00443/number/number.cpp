#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[1001],b=0,c;
    string d;
    cin>>d;
    for(int i=0;i<d.size();i++){
        if(d[i]>='0' and d[i]<='9'){
            a[b]=d[i]-'0';
            b++;
        }
    }
    for(int j=0;j<b;j++){
    for(int i=1;i<b;i++){
        if(a[i]>a[i-1]){
            c=a[i];
            a[i]=a[i-1];
            a[i-1]=c;
        }
    }
    }
    for(int i=0;i<b;i++){
        cout<<a[i];
    }
    return 0;
}
