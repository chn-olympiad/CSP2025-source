#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char c:s){
        if(c>='0' && c<='9'){
            a[(int)(c-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]--){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
/*
JJJJJJJJJJ   RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
J   JJ       RP++
JJ  JJ       RP++
 JJJJ        RP++
*/
//08:41 AC
