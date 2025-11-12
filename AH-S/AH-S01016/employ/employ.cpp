#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c[511],p[511],ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]),p[i]=i;
    if(n<=10)
    {
        do
        {
            int num=0,sum=0;
            for(int i=1;i<=n;i++)
            {
                if(num>=c[p[i]]) ++num;
                else if(s[i-1]=='0') ++num;
                else ++sum;
            }
            if(sum>=m) ++ans;
        }while(next_permutation(p+1,p+n+1));
        printf("%d",ans);
        return 0;
    }
	return 0;
}
