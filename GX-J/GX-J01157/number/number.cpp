//sout(a+1;a+n+1);
#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b+=a[i];
        }
    }
    for(int i=0;i<=b.size();i++){
        for(int i=0;i<=b.size();i++){
            if(b[i]-b[i+1]<0){
                swap(b[i],b[i+1]);
            }
        }
    }
    cout<<b;
    return 0;
}
