#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
string s;
int sum;
int a[N];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int len = s.size();
    for(int i = 0;i < len;i++){
        a[i] = 0;
    }
    for(int i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[i] = s[i] - '0';
        }
        else{
            sum++;
        }
    }
    sort(a,a + len,cmp);
    for(int i = 0;i < len - sum;i++){
        cout << a[i];
    }
    return 0;
}
