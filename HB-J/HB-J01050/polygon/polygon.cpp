#include<bits/stdc++.h>
using namespace std;
int jishu[10];
string s;
string toer(int n,int weishu){
    string ans="";
    while(n){
        int x=n%2;
        n/=2;
        ans.push_back(x+'0');
    }
    int qwer=ans.size();
    if(ans.size()<weishu){
        for(int i=0;i<weishu-qwer;i++)ans.push_back('0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
long long nowmax,nowcnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    long long zongfanganshu=1<<n;
    for(long long i=1;i<zongfanganshu;i++){
        nowcnt=0;
        nowmax=0;
        string s=toer(i,n);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(a[i]>nowmax)nowmax=a[i];
                nowcnt+=a[i];
            }
        }
        if(nowcnt>nowmax*2){
            cnt++;
        }
        cnt%=998244353;
    }
    cout<<cnt;

    return 0;
}
