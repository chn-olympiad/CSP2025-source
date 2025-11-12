#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
string s;
long long a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long l = s.length();
    for(int i = 0;i<l;i++){
        int lon=s[i]-'0';
        if(lon>=0&&lon<=9)
            a[lon]++;
    }
    for(int i = 9;i>=0;i--)
        for(int j = 1;j<=a[i];j++)
            cout<<i;
    return 0;
}
