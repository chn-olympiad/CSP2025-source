#include<bits/stdc++.h>
#define int long long
#define fors(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+500;
string s;
int a[N],n,m;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int m=s.size();
    //cout<<m;
    fors(i,0,m-1){
        if(s[i]>='0'&&s[i]<='9'){
            a[++n]=s[i]-'0';
        }
    }
    sort(a+1,a+1+n,cmp);
    fors(i,1,n){
        cout<<a[i];
    }
    return 0;
}
