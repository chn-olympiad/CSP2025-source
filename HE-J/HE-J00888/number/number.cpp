#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[10005],n;
    n=a.length();
    int sum=-1;
    for(int i=0;i<n;i++){
        if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
            sum++;
            b[sum]=a[i]-48;
        }
    }
    sort(b,b+sum);
    for(int i=sum;i>=0;i--){
        cout<<b[i];
    }

    return 0;
}
