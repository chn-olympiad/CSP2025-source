#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <array>

using namespace std;

#define fori(i,a,b)     for(int i=(a);i<=(b);i++)
#define fori0(i,a,b)    for(int i=(a);i<(b);i++)
#define ford(i,a,b)     for(int i=(a);i>=(b);i--)
#define rgall(a)        (a).begin(),(a).end()
#define rgany(a,l,r)    (a).begin()+(l),(a).begin()+(r)
#define rgn(a,n)        rgany(a,0,n)
#define rgo1(a,n)       rgany(a,1,n+1)

ifstream cin("employ.in");
ofstream cout("employ.out");

array<int,501> va;
array<int,11> vp;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m>>s,s=' '+s;
    fori(i,1,n)
        cin>>va[i],vp[i]=i;
    sort(rgo1(va,n));
    int ans=0;
    do
    {
        int a=0,b=0;
        fori(i,1,n)
        {
            if(s[i]=='0'||va[vp[i]]<=a)
                ++a;
            else
                ++b;
        }
        ans+=b>=m;
    }while(next_permutation(rgo1(vp,n)));
    cout<<ans;
    return 0;
}