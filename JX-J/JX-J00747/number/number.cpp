#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
string s;
int n,m,t[N],cnt=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);//please open it
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[cnt++]=(s[i]-'0');
        }
    }
    sort(t+1,t+cnt,cmp);
    for(int i=1;i<cnt;i++)cout<<t[i];
    return 0;
}
