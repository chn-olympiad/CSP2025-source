#include<bits/stdc++.h>
using namespace std;
bool b[500];
int main()
{
    unsigned long long n,m,r;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    cin>>m;
    r=1;
    for(int i=1;i<=m;i++){
        char tmp;
        tmp=getchar();
        b[i]=(tmp=='1');
    }
    for(long i=1;i<=n;i++){
        r*=i;
    }
    cout<<r%998244353<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
