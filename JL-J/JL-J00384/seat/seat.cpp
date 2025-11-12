#include<bits/stdc++.h>
using namespace std;
string a;
int b[1100000],c[1100000],k=0;
int main()
{
    freopen("number.in","r","in");
    freopen("number.out","w","out");
    cin>>a;
    int x=a.length;
    for(int i=0;i<x;i++){
        b[i]=a[i]-'0';
        if((b[i]>=0) && (b[i]<=9){
            c[k]=b[i];
            k++;
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<k-2;j++){
            if(c[j]>c[j+1]){
                swap(c[j],c[j+1])
            }
        }
    }
    for(int i=k-1;i>=0;i--) cout<<c[i];
    number.in;
    number.out;
    return 0;
}
