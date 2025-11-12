#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],num,sum,p;
char s;
bool check(int a)
{
    a=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(s==0){
            a++;
        return false;
    }
    if(s==1){
        return true;
    }
    for(int i=1;i<=n;i++){
        if(max(a,c[i])==a){
            return false;
        }
        else{
            return true;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        if(check(i)==true){
            num++;
        }
        if(num>=m){
            p++;
        }
        if(p>998244353){
            p=998244353;
        }
    }
    cout<<p;
    return 0;
}
