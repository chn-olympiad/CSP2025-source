#include<bits/stdc++.h>
using namespace std;
int a[500005];
string zhuan(int x)
{
    string ans="";
    int a[500005],i=0;
    while(x)
    {
        a[i++]=x%2;
        x/=2;
    }
    for(int j=i-1;j>=0;j--) ans+=(char)a[j]+48;
    return ans;
}
string yh(int l,int r)
{
    string x,s="";
    x=zhuan(a[l]);
    int lenx=x.length(),j;
    for(int i=l+1;i<=r;i++)
    {
        string y=zhuan(a[i]);
        int leny=y.length();
        s="";
        int minn=min(lenx,leny);
        for(j=1;j<=minn;j++)
        {
            if(x[j]==y[j]) s+='0';
            else s+='1';
        }
        while(j<=lenx||j<=leny) s+='1',j++;

        x=s;
        lenx=x.length();
    }
    return s;
}
int zhuan1(string s)
{
    int x=0,len=s.length(),ans=0;
    for(int i=len-1;i>=0;i--,x++)
    {
        if(s[i]=='1') ans+=pow(2,x);
    }
    return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=1,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++)
    {
        if(a[i]==k) ans++;
        for(int j=1;j<i;j++)
        {
            cout<<j<<" "<<i<<endl;
            if(zhuan1(yh(j,i))==k) ans++;
        }
    }
	cout<<ans;
	return 0;
}
