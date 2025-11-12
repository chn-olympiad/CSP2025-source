#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,d;
    int q,j[10000],w=0,o=0,b,c;
    cin>>a;
    while(o<a.size()){
        if(char(a[o])!='0' and char(a[o])!='1' and char(a[o])!='2' and char(a[o])!='3' and char(a[o])!='4' and char(a[o])!='5' and char(a[o])!='6' and char(a[o])!='7' and char(a[o])!='8' and char(a[o])!='9'){
            o+=1;
            continue;
        }
        else{
            j[w]=a[o];
            w=w+1;
            }
        o+=1;
        }
    for(int l=0;l<w;l++){
        for(int u=1;u<w;u++){
            if(j[l]>j[u-1]){
                b=j[l];
                j[l]=j[u-1];
                j[u-1]=b;
            }
        }
    }
    for(int h=0;h<w;h++){
        cout<<j[h]-48;
    }
    return 0;
}
