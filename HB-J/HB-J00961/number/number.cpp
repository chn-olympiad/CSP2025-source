#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000086],sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]+=s[i]-'0';
            sum++;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=n-sum;i--){
        cout<<a[i];
    }
    return 0;
}
