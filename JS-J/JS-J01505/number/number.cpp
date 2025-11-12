#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int N=1e6+5;
int a[N],sum;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            sum++;
            a[sum]=s[i]-48;
        }
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
