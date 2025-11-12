#include<bits/stdc++.h>
using namespace std;
string s,b="0123456789";
long long a[1000001],l,j=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0' and s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    j--;
    sort(a+1,a+1+j);
    for(int i=j;i>=1;i--){
        cout<<b[a[i]];
    }
    return 0;
}
