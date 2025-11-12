#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r"," std.in");
    freopen("number.out","w"," std.out");
    string n;
    cin>> n;
    char a;
    string x;
    int i,j;
    for(i =0;i< n.size;i++){
        if(a[i]>='0'&&a[i]<='9') {
                a[i]= x[i];
        }
    }
    int maxn =0;
    for(j =1;j< x.size;j++){
        maxn = x[0];
        if(x[j]>maxn) {
            x[j] = maxn;
            cout<< maxn;
        }

    }
    return 0;
}
