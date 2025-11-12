#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c;
	cin>>t>>n;
		int ans=0;
	while(t--)
	{
	
	for(int i=0;i<n;i++)
	{
     cin>>a>>b>>c;
	
			if(b>=a)  swap(a,b);
			if(c>=b)  swap(b,c);
			if(b>=a)  swap(a,b);
			ans+=a;
	}//paixu
}
cout<<ans<<endl;
	
	return 0;
}
