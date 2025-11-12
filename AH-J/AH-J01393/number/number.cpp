#include<bits/stdc++.h>
using namespace std;
int t[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    string a;
    cin>>a;
    int l=a.size();
    for(int i=0;i<l;i++){
        if(a[i]>='0'&&a[i]<='9'){
            t[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(t[i]--){
            cout<<i;
        }
    }
    return 0;
}
