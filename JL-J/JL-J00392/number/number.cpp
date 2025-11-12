#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    int a[str.size()];
    int b=0;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            a[b]=str[i]-'0';
            b++;
        }
    }
    sort(a,a+b);
    for(int i=b-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
