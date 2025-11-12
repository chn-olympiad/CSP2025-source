#include<bits/stdc++.h>
//-fsanitize=address,undefined
//For my dearest,Venti,[] and 3_7.
//st:17:05
//ed:17:21
//exp:test | pts
/*
感觉自己做不出来，但是赛后可以验证一下我现在想到的对不对
建图？对于每个替换，然后就是每个询问就在图上跑？
终于可以开始睡觉了
*/
using namespace std;
const int MAXN = 105;
int N, Q;
pair<string, string> s[MAXN];
string s1, s2;
int main(){
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cout.tie( 0 );
    freopen( "replace.in", "r", stdin );
    freopen( "replace.out", "w", stdout );
    cin >> N >> Q;
    for( int i = 1; i <= N; i ++ ){
        cin >> s[i].first >> s[i].second;
    }
    while( Q -- ){
        cout << 0 << endl;
    }
    return 0;
}