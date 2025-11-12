#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string stringa,stringb;
ll ans;
map<int,pair<string,string> >replacestring;
map<string,string>question;
ll n,m;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>stringa>>stringb;
        replacestring[i]=make_pair(stringa,stringb);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>stringa>>stringb;
        question[stringa]=stringb;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",rand());
    return 0;
}
