#include<bits/stdc++.h>
using namespace std;
int b[1005],j=0,num;
int main(){
    //freopen("number.in","r",stdin);
    string a;
    cin>>a;
    for(int i=0;i<sizeof(a);i++){
        if('0'<=a[i] && a[i]<='9'){
            b[j]=a[i]-'0';
            j++;
        }
    }
    for(int i=0;i<j;i++){
        for(int k=i;k<j;k++){
            if(b[i]<b[k])
                swap(b[i],b[k]);
        }
    }
    for(int i=0;i<j;i++)
        cout<<b[i];
    //freopen("number.out","w",stdout);
    return 0;
}
