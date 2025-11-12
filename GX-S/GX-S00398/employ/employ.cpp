#include<iostream>
#include<cstring>
using namespace std;
const int N=998244353;
string s;
int n,m;
int c[510]={};
long long sum=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int lens=s.size();
    if(m==n){
        for(int i=0;i<lens;i++){
            if(s[i]==0){
                cout<<0;
                return 0;
            }
        }
        for(int i=1;i<=m;i++){
            sum=sum*i;
        }
        long long ans=sum%N;
        printf("%lld",ans);
    }else{
        int cnt=0;
        for(int i=0;i<lens;i++){
            if(s[i]=='1') cnt++;
        }
        if(cnt<m) cout<<0;
    }
    return 0;
}
