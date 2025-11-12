#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;

    cin>>s;
    long long j=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-48;
            j++;
        }
    }

    for(long long i=0;i<=j;i++){
        for(long long k=0;k<=j;k++){
            if(a[k]<a[k+1]){
                swap(a[k],a[k+1]);
            }
        }
    }
    for(long long i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
