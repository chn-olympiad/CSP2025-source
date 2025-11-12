#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,i,j,k,l,a[1000009];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9')a[++l]=s[i]-'0';
    }
    sort(a+1,a+l+1,cmp);
//    cout<<l<<endl;
    for(i=1;i<=l;i++)cout<<a[i];
    return 0;
}
