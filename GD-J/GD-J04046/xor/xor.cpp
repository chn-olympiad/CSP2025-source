#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool flg=true;
long long a[500005],k,num;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])flg=false;
	}
	if(k==0 && flg)
	{
		cout<<n/2;
		return 0;
	}
	else if(k==1)
	{
		for(int x=1;x<=n;x++){
			bool ling=1,yi=1;
		    while(ling||yi)
		    {
			    int i=1;
			    if(a[i]==0)ling=false;
			    if(a[i]==1)yi=false;
			    i++;
			    x=i;
	    	}
	    	if(!(ling||yi))cnt++;
	    }
	    cout<<cnt;
	    return 0;
	}
	else
	{
		return 0;
	}
	return 0;
}
