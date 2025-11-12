#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],j=1,o=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i];i++){
        if(s[i]>='0' && s[i]<='9'){
            a[j]=s[i]-'0';
            o++;
            j++;
        }
    }
    sort(a+1,a+o+1);
    for(int i=o;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
