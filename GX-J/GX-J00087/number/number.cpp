#include<bits/stdc++.h>
using namespace std;
string n;
int j=0,a[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0'&&n[i]<='9'){
            a[j]=n[i]-'0';
            j++;
        }
    }
    sort(a,a+j);
    for(int i=j-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
