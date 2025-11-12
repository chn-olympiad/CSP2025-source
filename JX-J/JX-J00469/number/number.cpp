#include <bits/stdc++.h>
using namespace std;
int b[1000]={0},c,d;
string a;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.ans","w",stdout);

    cin>>a;

    for(int i=0;i<sizeof(a);i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[d]=a[i]-'0';
            d++;
        }
    }
    for(int j=0;j<d;j++){
        for(int i=0;i<d;i++){
            if(b[i]<b[i+1]){
                c=b[i];
                b[i]=b[i+1];
                b[i+1]=c;
            }
        }
    }
    for(int i=0;i<d;i++){
            cout<<b[i];

    }
    return 0;
}
