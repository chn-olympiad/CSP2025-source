#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005];
int cnt=0;
bool used[5005];
void fun(string s,int need,int mx,int pos){
    //if(need>n)cout<<need<<endl;
    if(need<=0){
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=s[i];
        }
        if(sum>mx*2){
            cnt++;
            //out(s);
        }
        if(cnt==mod)cnt=0;
        return ;
    }
    for(int i=pos;i<n;i++){
        if(used[i])continue;
        used[i]=1;
        string t=s;
        t+=a[i];
        fun(t,need-1,max(mx,a[i]),i+1);
        used[i]=0;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        fun("",i,0,0);
    }
    cout<<cnt;
    return 0;
}
// 1 2 3 4 5 6 7 8 9
// 12345 12346 12347 12348 12349 13456 13457 13458 13459 14567 14568 14569 15678 15679
// 23456


//1 2 4
//1
//1 2 3 4
//4 123 124 234 1234
//12345
//123 124 125 134 135 145
//1234 1235 1245 1345
//


//n
