#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    string number;
    int num=0;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i]>='o'&&a[i]<='9'){
            number[num]=a[i];
            num++;
        }
    }
    for(int i=0;i<=number.size();i++){
        if(a[i]<=a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    cout<<number;
    return 0;
}
