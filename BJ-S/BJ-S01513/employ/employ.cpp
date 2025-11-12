#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int a[N],p[N];
string s;
int calc(){
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0' || cnt2>=a[p[i]]){
            cnt2++;
        }else{
            cnt1++;
        }
    }
    return (cnt1>=m);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    int ans=0;
    do{
        ans+=calc();
    }while(next_permutation(p+1,p+n+1));
    cout <<ans<<endl;
    return 0;
}
