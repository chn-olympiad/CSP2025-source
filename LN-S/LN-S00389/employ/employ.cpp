#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int f,uc,k,cc,f;
long long gantan(int m){
    long long re = 1;
    for (int i = 1;i<=m;i++) re *= i;
    return re;
}
int main(){
    //三！千！万！转！
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // 密码：Ren5Jie4Di4Ling5%
    int n,m;
    cin >> n >> m;
    long long ans = gantan(n)/(gantan(m)*gantan(n-m)) % MOD;
    cout << ans << endl;
    return 0;
}
/*
3 2
1 1 1
1 1 2
*/
/*
能写点是点，不知道ln有没有迷惑行为大赏
#include <bits.stdc++.h>
#include <bits\stdc++.h>
#include <bits/stdc++/h>
#include <bits/stdc++\h>
cosnt int MOD= 998244353
int mian(){
void mian(){
#include <windows.h>
#include <pargmas>
void main(){
fxxk
ccf
csp
cspj
csps
noi
NOIP
I AK IOI
luogu UID:I forget it :)
Honkai Star Rail UID:forget it 2:)
*/