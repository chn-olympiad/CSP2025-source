#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    int q=1;
    for (int i=0;i<n;i++){
        if (s[i]<='9'&&s[i]>='0'){
            a[q++]=s[i]-'0';
        }
    }
    sort (a+1,a+q);
    if (a[q-1]==0){
        cout<<0;
        return 0;
    }
    for (int i=q-1;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
