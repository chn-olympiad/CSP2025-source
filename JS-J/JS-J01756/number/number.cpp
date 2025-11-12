#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
string s;
int k=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            a[k]=(s[i]-'0');
            k++;  
        }
    }
    sort(a,a+k);
    for(int i=k-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}