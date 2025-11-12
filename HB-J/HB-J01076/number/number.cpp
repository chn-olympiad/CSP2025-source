#include <bits/stdc++.h>
int exch;
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<=a.size()-1;i++){
        if(a[i]>='a' && a[i]<='z'){
            a[i]='a';
        }
        else{
            continue;
        }
    }
    for(int i=0;i<=a.size()-1;i++){
        if(a.size()==0){
            break;
        }
        for(int j=0;j<=a.size()-1;j++){
            if(a[j]<a[j+1]){
                exch=a[j];
                a[j]=a[j+1];
                a[j+1]=exch;
            }
        }
    }
    for(int i=0;i<=a.size()-1;i++){
        if(a.size()==0){
            cout<<a;
            break;
        }
        if(a[i]>='0'&&a[i]<='9'){
            cout<<a[i];
        }
    }
    return 0;
}
