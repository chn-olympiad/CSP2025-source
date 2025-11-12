#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
long long rp;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            rp++;
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<rp;i++)cout<<a[i];
    return 0;
}
