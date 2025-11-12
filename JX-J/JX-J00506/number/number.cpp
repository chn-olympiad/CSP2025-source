#include <bits/stdc++.h>
using namespace std;
string s;
int b[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a,c=0,d=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        a=s[i];
        if(a<48||a>57) continue;
        b[c]=a-48;
        c++;
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<c+1;j++){
            if(b[j+1]>b[j]){
                swap(b[j+1],b[j]);
                d=1;
            }
        }
        if(d==0) break;
    }
    for(int i=0;i<c;i++){
        cout<<b[i];
    }
    return 0;
}
