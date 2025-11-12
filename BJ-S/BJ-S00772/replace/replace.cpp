#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1000000000000000000ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep_(i,a,b) for(int i=(a);i<(b);i++)
#define per_(i,a,b) for(int i=(a);i>(b);i--)
#define N 101
#define M 201
int n,q;
string s1[N],s2[N],t1,t2;
void mian(int argt){
    cin>>n>>q;
    rep(i,1,n){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        cin>>t1>>t2;
        int cnt=0;
        rep(i,1,n){
            rep(j,0,(int)t1.size()-(int)s1[i].size()){
                bool flag=1;
                rep_(k,0,t1.size()){
                    if(k<j||k>=j+s1[i].size()){
                        if(t1[k]!=t2[k]){
                            flag=0;
                            break;
                        }
                    }else{
                        if(t1[k]!=s1[i][k-j]||t2[k]!=s2[i][k-j]){
                            flag=0;
                            break;
                        }
                    }
                }
                if(flag){
                    cnt++;
                    break;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T=1;
    //cin>>T;
    rep(i,1,T){
        mian(i);
    }
}
/*
1. File IO
2. Array Size
3. Time
4. Memory
*/
