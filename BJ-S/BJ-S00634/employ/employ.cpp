#include <fstream>
using namespace std;
ifstream cin("employ.in");
ofstream cout("employ.out");
const int mod=998244353;
string str;
int n,m,ans;
int main()
{
    cin>>n>>m;
    cin>>str;
    str="*"+str;
    bool flag=true;
    for(int i=1;i<=m;i++)
    {
        if(str[i]==0)
            flag=false;
    }
    if(flag==true)
    {
        ans=1;
        for(int i=n;i>=2;i--)
        {
            ans*=i;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    else
        cout<<0<<endl;
}
