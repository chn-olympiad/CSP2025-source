#include <bits/stdc++.h>
using namespace std;
int main(){
    string c;
    int n=0,b=0,a[1000001];
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    n=c.length();
    for(int i=0;i<n;i++){
        if(c[i]-'0'<=9 && c[i]-'0'>=1){
            a[i]=c[i]-'0';
        }else if(c[i]-'0'==0){
            b+=1;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(a[i]>0){
            cout<<a[i];
        }else if(b>0){
            b--;
            cout<<a[i];
        }

    }



    return 0;
}
