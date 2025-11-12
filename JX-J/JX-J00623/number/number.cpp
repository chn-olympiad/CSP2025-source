#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >>s;
    int p=1;
    for(int i=0;i<(int)s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[p]=s[i]-'0';
            p++;
        }
    }
    sort(a+1,a+1+p);
    for(int i=p;i>=2;i--)cout << a[i];
    return 0;
}
