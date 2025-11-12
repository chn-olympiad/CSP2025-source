#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+5;
string s;
ll a[N];

bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;

    int l=s.size(),len=1;
    for(int i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[len]=s[i]-'0';
            len++;
        }
    }
    len--;
    sort(a+1,a+len+1,cmp);
    for(int i=1;i<=len;i++){
        cout << a[i] ;
    }
    return 0;
}

