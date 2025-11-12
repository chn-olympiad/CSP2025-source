#include <bits/stdc++.h>
using namespace std;
int b[1000005];
bool cmp(int a,int b){
    return a>b;
}
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int j=0;
    for(int i=0;i<int((a.length()));i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[j]=int(a[i]-48);
            j++;
        }
    }
    sort(b,b+j,cmp);
    for(int i=0;i<j;i++){
        cout<<b[i];
    }
    return 0;
}
