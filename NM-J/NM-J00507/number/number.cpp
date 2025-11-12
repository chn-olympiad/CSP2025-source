#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000100],l,sum;
int abc(int x,int y){
    return x>y;
}
int main(){
    freopen("numder.in","r",stdin);
    freopen("numder.out","w",stdout);
    cin>>a;
    l=a.size();
    for(int i=0;i<=l;i++){
        if(a[i]>='0'&&a[i]<='9'){
            sum++;
            b[sum]=a[i]-'0';
        }
    }
    sort(b+1,b+sum+1,abc);
    for(int i=1;i<=sum;i++){
        cout<<b[i];
    }
    return 0;
}
