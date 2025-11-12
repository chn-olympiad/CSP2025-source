#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            j++;
            a[j]=s[i]-'0';

        }
    }
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
