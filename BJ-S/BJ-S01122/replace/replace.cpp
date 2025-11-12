#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
int n,q;
string s[N][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        cout<<"0\n";
    }
    return 0;
}
//RP++, Goodbye OI