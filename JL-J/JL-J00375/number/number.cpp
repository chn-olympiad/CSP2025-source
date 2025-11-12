#include<bits/stdc++.h>
using namespace std;
    int a[1000010]={0},i=1,o=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(i=0;i<n.length();i++){
        if(n[i]>='0'&&n[i]<='9'){
            a[i]=n[i]-'0';
            o++;
        }else{
            continue;
        }
    }
    if(n.length()==1){
        cout<<a[n.length()-i];
        return 0;
    }
    sort(a,a+i);
    for(int j=i-1;j>=n.length()-o;j--){
        cout<<a[j];
    }
    return 0;
}
