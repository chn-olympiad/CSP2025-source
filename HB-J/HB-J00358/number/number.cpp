#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sovle(){
    string s;
    int a[1000010];
    ll sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[sum]=int(s[i])-48;
            sum++;
        }
    }
    sort(a,a+sum);
    for(int i=sum-1;i>=0;i--){
        cout<<a[i];
    }
}
int main(){
    ios::sync_with_stdio();
    cin.tie();
    cout.tie();
    freopen("number3.in","r",stdin);
    freopen("number.out","w",stdout);
    int t=1;
    while(t--){
        sovle();
    }
    return 0;
}
