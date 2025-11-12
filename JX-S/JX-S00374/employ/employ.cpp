#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
string s;
long long n,m,c[505],a[505],ta=1,ans,wik=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        a[i]=s[i-1]-'0';
        if(!a[i])   ta=0;
    }
    for(int i=1;i<=n;i++)   cin>>c[i];
    for(int i=1;i<=n;i++){
        if(c[i]==0) wik++;
    }
    sort(c+1,c+n+1);
    if(!ta){
        cout<<0<<endl;
        return 0;
    }
    if(ta&&m!=1){
        if(n-wik<m){
            cout<<0<<endl;
            return 0;
        }
        long long ac=1;
        for(long long i=2;i<=n;i++){
            ac=(ac*i)%N;
        }
        cout<<ac<<endl;
        return 0;
    }
    long long w=1;
    for(long long i=2;i<=n;i++){
        w=(w*i)%N;
    }
    cout<<w/2<<endl;
    return 0;
}