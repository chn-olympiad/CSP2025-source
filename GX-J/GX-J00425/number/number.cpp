#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long a[100000],n=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=(long long)(s[i]-'0');
            n++;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }

    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
