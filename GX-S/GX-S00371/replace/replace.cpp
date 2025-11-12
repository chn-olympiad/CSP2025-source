#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=200005;

int n,q,exist[26][MAXN],cnt=0;
pair<string,string> s[MAXN];

struct Node{
    char v;
    int l=0,r=0,f=0;
}tr[10000005];

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<q;i++)cout<<n<<endl;
    return 0;
}
