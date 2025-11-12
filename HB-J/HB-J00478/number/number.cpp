#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int k=0;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0' && a[i]<='9'){
            ans[++k]=a[i]-'0';
        }
    }
    sort(ans+1,ans+k+1);
    for(int i=k;i>=1;i--)
        printf("%d",ans[i]);
    cout<<endl;
    return 0;
}
