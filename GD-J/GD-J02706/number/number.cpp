
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
long long n,m,i,j,k,a[N],cut=0;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cut++]=s[i]-'0';
        }
    }
    sort(a,a+cut);
    for(i=cut-1;i>=0;i--)
    {
        cout<<a[i];
    }
    /*
	for(;;) cout<<"rp++"<<"\n";
	*/
    return 0;
}
