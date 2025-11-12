#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int sb[1000000]={0};
    long long m=0,cut=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if((a[i]<='9')&&(a[i]>='0')){
            sb[m]=int(a[i])-48;
            m++;
        }
    }
    sort(sb,sb+m);
    for(int i=m-1;i>=0;i--){
        if(sb[i]!=0){
            cut=(cut*10)+sb[i];
        }else{
            cut=cut*10;
        }
    }
    cout<<cut;
    return 0;
}
