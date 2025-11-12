#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000001];
int manynum=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n.length();i++){
        if(n[i]>='0'&&n[i]<='9'){
            a[manynum]=n[i]-'0';
            manynum++;
        }
    }
    manynum-=1;
    for(int j=1;j<=manynum;j++){
        for(int i=2;i<=manynum;i++){
            if(a[i]>=a[i-1]){
                swap(a[i],a[i-1]);
            }
        }
    }
    for(int i=1;i<=manynum;i++){
        cout<<a[i];
    }
    return 0;
}
