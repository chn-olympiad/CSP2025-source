#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int b[1000005],i,j;
    cin >> a;
    j=1;
    for(i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            b[j]=a[i]-'0';
            j++;
        }
    }
    j--;
    sort(b+1,b+1+j);
    for(i=j;i>=1;i--){
        cout << b[i];
    }
    return 0;
}
