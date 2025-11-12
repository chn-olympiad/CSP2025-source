#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
string s;
int a[100005],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            n++;
            a[n]=s[i]-'0';
        }
    }
    sort(a+1,a+n+1);
    bool if0=0;
    for(int i=n;i>=1;i--){
        if(a[i]>0){
            if0=1;
            cout<<a[i];
        }
        else if(a[i]==0&&if0==1)  cout<<a[i];
    }
    if(if0==0)  cout<<0;
    return 0;
}
