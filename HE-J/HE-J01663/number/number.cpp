#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    int b,c=0;
    int d[1000];
    getline(cin,a);
    b=a.size();
    if(b!=0){
        for(int i=0;i<b;i++){
            if((a[i]>='0')and(a[i]<='9')){
                d[c]=a[i]-48;
                c+=1;
            }
        }
    }else{
        if((a[0]>='0')and(a[0]<='9')){
            cout<<a[0];
        }
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
        return 0;
    }

    sort(d,d+c);
    for(int i=c-1;i>=0;i--){
        cout<<d[i];
    }
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    return 0;
}
