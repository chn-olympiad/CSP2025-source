#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,ans;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
    	cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m);
	reverse(a,a+n*m);
	for(int i=0;i<n*m;i++)
    {
    	if(a[i]==r)
    	{
    		ans=i+1;
		}
	}
	if(ans<=n)cout<<1<<" "<<ans;
	if(ans>n)
	{
		cout<<(ans/n)+(ans%n)<<" ";
		if(((ans/n)+(ans%n))%2==0)
		{
			cout<<n-(ans%n)+1;
		}
		else
		{
			cout<<1+(ans%n)-1;
		}
	}
	fclose(stdin);
    fclose(stdout);
    return 0;
}
