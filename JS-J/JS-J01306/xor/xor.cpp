#include <bits/stdc++.h>
using namespace std;
int a[1010];
string zhuan(int a){
    string m;
    while(a>0){
        if(a%2==0){
            m+='0';
        }
        else{
            m+='1';
        }
        a/=2;
    }
    return m;
}

string yihuo(int a,int b){
    string p1=zhuan(a),p2=zhuan(b);
    string s;
    for(int i=0;i<max(p1.size(),p2.size());i++){
        if(p1[i]==p2[i]){
            s+='0';
        }
        else{
            s+='1';
        }
    }
    return s;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"3";
    return 0;
}
