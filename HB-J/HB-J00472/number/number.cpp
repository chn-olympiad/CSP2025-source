#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    int b[7];
    int c,d;
    for(int i=1;i<=a.size();i++){
        if(a[i]-'0'<=9||a[i]-'0'<=9){
            b[i]=a[i];
            c++;
        }
    }
    for(int i=1;i<=c;1++){
        for(j=1;j<=i;j++){
            if(b[i]>a[j-1]||a[j-1]<=9){
                d=b[i-1];
                b[i-1]=b[i];
                b[i]=d;
            }
        }
    }
for(int i=0;i<=c;i++){
    cout<<b[i];
}
}
