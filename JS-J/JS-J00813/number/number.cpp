#include <bits/stdc++.h>
using namespace std;
string s;
long long a[2000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long n=0,l=s.length();
    for(long long i=0;i<=l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n);
    for(long long i=n-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
