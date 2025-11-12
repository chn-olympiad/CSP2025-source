#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 500 + 10,mod = 99844353;
int a[N];

void solved() {
    int n,m; cin >> n >> m;
    string s; cin >> s;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    int cnt = 0;
    for(int i = 0;i < n;i ++) if(s[i] == '1') cnt ++;
    int sum = 1;
    while(cnt != 0) sum *= cnt --;
    cout << sum << endl;
    return ;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
 //    int t; cin >> t; while(t --)
    solved();
    return 0;
}
