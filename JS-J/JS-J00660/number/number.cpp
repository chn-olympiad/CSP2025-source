#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],k=1;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a+1,a+k);
    k--;
    if(a[k]==0){
        cout<<0;
        return 0;
    }
    for(int i=k;i>=1;i--)cout<<a[i];
    return 0;
}
