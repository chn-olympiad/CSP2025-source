#include<bits/stdc++.h>
using namespace std;
long long n,m,k,q;
string t1,t2,a,b;
string s[200010],s_[200010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(long long i=0;i<n;i++){
        cin>>a>>b;
        s[i]=a;
        s_[i]=b;
    }
    while(q--){
            long long cnt=0;
        cin>>t1;
        cin>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<'\n';
            continue;
        }
        long long len=t1.length();
        for(long long i=0;i<len;i++){
            for(long long j=1;j<=len-i;j++){
                string s1=t1.substr(i,j);
                string s2=t2.substr(i,j);
                string sx1=t1.substr(0,i);
                string sx2=t2.substr(0,i);
                string sy1=t1.substr(i+j);
                string sy2=t2.substr(i+j);
                for(long long k=0;k<n;k++){
                    if(s[i]==s1&&s_[i]==s2&&sx1==sx2&&sy1==sy2){
                        cnt++;
                        break;
                    }
                }

            }


    }
    cout<<cnt<<'\n';
    }
    return 0;

}
