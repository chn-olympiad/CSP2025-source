#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    cin>>s;
    int k=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]+=s[i]-'0';
            k++;
        }
    }
    k--;
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
