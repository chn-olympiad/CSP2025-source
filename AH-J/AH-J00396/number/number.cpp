#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int k[13]={};
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            k[a[i]-'0']++;
        }
    }
    int flag=0;
    for(int i=9;i>=0;i--){
        if(k[i]>0&&i!=0){
            flag=1;
        }
        while(k[i]>0&&flag==1){
            cout<<i;
            k[i]--;
        }
    }
    if(flag==0){
        cout<<0;
    }










    return 0;
}
