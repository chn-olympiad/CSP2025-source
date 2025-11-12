#include <bits/stdc++.h>
using namespace std;
long long ans,mo=998244353;
int n,m,c[505];
bool a=1;
string s;

long long jc(int a)
{
    long long ans=0;
    for(int i=2;i<=a;i++)
    {
        ans*=i;
        ans%mo;
    }
    return ans%mo;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n,m,s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(m==n){
        cout << jc(n);
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]==0) a=0;
    }
    if(a==1) cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
