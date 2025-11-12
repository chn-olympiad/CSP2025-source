includes<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long s[N];
int main()
{
int n,m;
cin>>n>>m;
for(int i=1,i<=n,i++)
{
    int x;
    cin>>x;
    s[i]=s[i-1]+x
}
while(m--)
{
 int r;
 int l=1;
 cin>>r;
 cout>>s[r]-s[i-1]<<endl;
}
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
return 0;
}
