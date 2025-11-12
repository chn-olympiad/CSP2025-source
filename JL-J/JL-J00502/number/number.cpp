#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long k=0;
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a,a+k,cmp);
    for(long long i=0;i<k;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
