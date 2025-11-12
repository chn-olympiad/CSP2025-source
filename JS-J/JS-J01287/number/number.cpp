#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
string s;
int a[N],j=1;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            a[j++]=s[i]-'0';
            if(a[j-1]<a[j]){
                int t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
    }
    sort(a+1,a+j,greater<int>());
    for(int i=1;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
