
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
string a[N],b[N];
ll cnt;
int main(){
   freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    while(q--)
    {
        string x,y;
        cin>>x>>y;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(x.find(a[i])<=x.size()&&y.find(b[i])<=y.size())
            {
                if(x.substr(0,x.find(a[i]))+x.substr(x.find(a[i])+a[i].size(),x.size()-1)==y.substr(0,y.find(b[i]))+y.substr(y.find(b[i])+b[i].size(),y.size()-1))
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
