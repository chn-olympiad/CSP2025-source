#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int k=0;
int a[N];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if('0'<=s[i]&&s[i]<='9'){
            k++;
            a[k]=s[i]-'0';
        }
    }
    sort(a+1,a+1+k);
    for(int i=k;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
