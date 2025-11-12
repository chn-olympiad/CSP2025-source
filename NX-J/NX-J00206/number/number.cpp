#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n=1000010;
    long long s[1000010];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;i<=i;j++){
            if(s[j]>s[i]){
                swap(s[i],s[j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<s[i];
    }
    return 0;
}
