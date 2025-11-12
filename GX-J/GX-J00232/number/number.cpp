#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
string s;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long l=0;
    long long n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            l++;
            a[l]=s[i]-'0';
        }
    }
    sort(a+1,a+l+1,cmp);
    for(int i=1;i<=l;i++){
        cout<<a[i];
    }
    return 0;
}
