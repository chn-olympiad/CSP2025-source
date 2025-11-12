#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+2;
ll a[N],ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0,j=1;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans=j;
            a[j]=(s[i]-48);
            j++;
        }
    }
    sort(a+1,a+ans+1);
    for(int i=ans;i>=1;i--) cout<<a[i];
    cout<<endl;
    return 0;
}