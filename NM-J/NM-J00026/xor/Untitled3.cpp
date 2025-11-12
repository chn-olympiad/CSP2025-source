#include<bits/stdc++.h> 
using namespace std;
int a,c,d,op,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >>a;
    int b[a];
    cin >>c;
    cin >>d;
    cnt=a-1;
    for(int i=0;i<cnt ;i++){
        if(i!=0)op=op|b[i];
        else op=b[i];
    }
    cout<<op;
    return 0;
}

