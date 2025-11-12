#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,ans={};
    char a[1000005];
    int j=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
    }
    for(int i=0;i<j;i++){
            for(int k=0;k<j;k++)
        if(a[k]<a[k+1]){
            swap(a[k],a[k+1]);
        }
    }
    for(int i=0;i<j;i++){
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
