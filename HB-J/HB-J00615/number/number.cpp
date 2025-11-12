#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int z,l=0;
    cin>>a;
    z=a.size();
    for(int i=0;i<z;i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[l]=a[i]-48;
            l++;
        }
    }
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(b[i]<b[j]){
                int t;
                t=b[i];
                b[i]=b[j];
                b[j]=t;
            }
        }
    }
    for(int i=0;i<l;i++){
        cout<<b[i];
    }
    return 0;
}
