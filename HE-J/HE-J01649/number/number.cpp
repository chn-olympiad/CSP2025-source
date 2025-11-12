#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],j;
string str;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++){
        if('0'<=str[i] && str[i]<='9'){
            a[++j]=int(str[i]-'0');
        }
    }
    sort(a+1,a+1+j);
    for(int i=j;i>=1;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
