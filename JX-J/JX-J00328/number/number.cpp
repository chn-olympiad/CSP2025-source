#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    long long n;
    n=s.size();
    int m=0;
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[m]=int(s[i])-48;
            m++;
        }
    }

    sort(a,a+m);
    for(int i=m-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
