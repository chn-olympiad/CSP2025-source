#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&'9'>=s[i]){
            long long b=s[i]-'0';
            a[b]++;
        }
    }
    long long cnt=0;
    for(int i=9;i>=0;i--){
        if(a[i]>=1){
            cnt=i;
            break;
        }
    }
    for(long long i=cnt;i>=0;i--){
        long long j=a[i];
        while(j>0){
            cout<<i;
            j--;
        }
    }
    return 0;
}
