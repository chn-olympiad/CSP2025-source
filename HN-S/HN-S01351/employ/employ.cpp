#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    scanf("%d %d",&n,&m);
    string s;
    cin>>s;
    vector<int>c(n+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    vector<int>p(n);
    iota(p.begin(),p.end(),1);
    int ans=0,val=0;
    do{
        int refuse=0;
        for(int i=0;i<n;i++)
        {
            int id=p[i];
            if(s[i]=='0'||refuse>=c[id])
                refuse++;
        }
        ans+=(refuse<=n-m);
    }while(next_permutation(p.begin(),p.end()));
    printf("%d\n",ans);

    return 0;
}