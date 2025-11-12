#include <bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),flag=1;
    for(int i=0;i<n;i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=1;i<=9;i++){
        if(a[i]>0){
            flag=0;
        }
    }
    if(flag==1){
        cout<<0;
    }
    else{
        for(int i=9;i>=0;i--){
            for(int j=1;j<=a[i];j++){
                cout<<i;
            }
        }
    }

    cout<<endl;
    return 0;
}
