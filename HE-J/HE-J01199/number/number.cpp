#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000001];
    int a[1000001],j=0;
    cin>>s;
    for(int i=0;i<length(s);i++){
        if(s[i]>="0" && s[i]<="9"){
            a[j]=s[i]-"0";
            j++;
    }
    for(int i=j-1;i>0;i-=1){
        for(int k=i;k>0;k-=1){
            if(a[k]>a[k-1]){
                int t=a[k];
                a[k]=a[k-1];
                a[k-1]=t;
            }
        }
    }
    for(int i=0;i<j;i++){
        cout<<a[j];
    }
    return 0;
}
