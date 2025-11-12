#include<bits/stdc++.h>
using namespace std;
string s,b;
int a[12];
int sp(string x){
    int i=0;
    while (i<x.size()){
        if(x[i]>'9'||x[i]<'0'){
            i++;
        }
        else{
            if(x[i]=='0'||x[i]=='1'||x[i]=='2'||x[i]=='3'||x[i]=='4'||x[i]=='5'||x[i]=='6'||x[i]=='7'||x[i]=='8'||x[i]=='9'){
                int t=x[i];
                a[t-48]++;
                i++;
            }
        }
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int g=9,d=0;
    cin>>s;
    sp(s);
    while(g>=0){
        if(a[g]>0){
            b[d]=g+48;
            a[g]--;
            cout<<b[d];
            d++;
        }
        else{
            g--;
        }
    }
    return 0;
}
