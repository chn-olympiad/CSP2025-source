#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000],n,b[1000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]<=9&&s[i]>=1){
            a[n]=s[i];
            n++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++)
            if(a[i+1]>a[i]){
                b[i]=a[i+1];
                b[i+1]=a[i];
            }
    }
    for(int i=0;i<n;i++)
        cout<<b[i];
    return 0;
}
