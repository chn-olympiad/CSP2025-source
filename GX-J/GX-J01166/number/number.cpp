#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int n,z,a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]-'0'<=9&&s[i]-'0'>=0){
            a[z]=s[i]-'0';
            z++;
        }
    }
    sort(a,a+z);
    for(int i=z-1;i>=0;i--)cout<<a[i];
    return 0;
}
