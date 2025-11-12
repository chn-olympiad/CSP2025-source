#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
char a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i];
            k++;
        }
        else continue;
    }
    sort(a,a+k);
    for(int i=k-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}