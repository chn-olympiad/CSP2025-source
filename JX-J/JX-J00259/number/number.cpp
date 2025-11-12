#include<bits/stdc++.h>
using namespace std;
int k;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","W",stdout);
    string a;file:///home/noi/Desktop/JX-J00259/seat/seat.cpp

    int b[100003];
    cin>>a;
    int len=a.size();
    for(int i=0;i<lenfile:///home/noi/Desktop/JX-J00259/number/number.cpp
;i++){
        if(!(a[i]>='a'&& a[i]<='z')){
            b[k]=a[i]-48;
            k++;
        }
    }
    sort(b,b+k);
    for(int i=k-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
