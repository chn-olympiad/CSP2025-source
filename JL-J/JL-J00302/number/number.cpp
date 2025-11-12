#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n = s.size();
    int c = 0;
    for(int i = 0;i < n;i++){
        if(s[i]<= '9' && s[i] >= '0'){
            a[c] = s[i];
            c++;
        }
    }
    sort(a,a+n,cmp);
    long long t = 0;
    for(int i = 0;i < c;i++){
        char m = a[i];
        cout << m;
    }
    return 0;
}
