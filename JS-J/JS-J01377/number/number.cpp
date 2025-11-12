#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(char x,char y){
    return x>y;
}
long long a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++){
        if(isdigit(s[i])){
            a[(s[i]-48)]++;
        }
    }
    if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0){
        cout<<0<<endl;
        return 0;
    }
    for(ll i=1;i<=a[9];i++) cout<<"9";
    for(ll i=1;i<=a[8];i++) cout<<"8";
    for(ll i=1;i<=a[7];i++) cout<<"7";
    for(ll i=1;i<=a[6];i++) cout<<"6";
    for(ll i=1;i<=a[5];i++) cout<<"5";
    for(ll i=1;i<=a[4];i++) cout<<"4";
    for(ll i=1;i<=a[3];i++) cout<<"3";
    for(ll i=1;i<=a[2];i++) cout<<"2";
    for(ll i=1;i<=a[1];i++) cout<<"1";
    for(ll i=1;i<=a[0];i++) cout<<"0";
    cout<<endl;
    return 0;
}