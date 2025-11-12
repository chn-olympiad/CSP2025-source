#include <bits/stdc++.h>
using namespace std;
int f[100005];

int main()
{
	int t;
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		long long cnt=0;
		int aa=0,bb=0,cc=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){aa++;cnt+=a;f[i]=max(b,c)-a;
			}
			else if(b>=a&&b>=c){bb++;cnt+=b;f[i]=max(a,c)-b;
			}
			else if(c>=b&&c>=a){cc++;cnt+=c;f[i]=max(b,a)-c;
			}
		} 
		sort(f+1,f+n+1);
		if(aa<=n/2&&bb<=n/2&&cc<=n/2)cout<<cnt<<"\n";
		else
		{
			
			if(aa>n/2)for(int i=n;i>n-(aa-n/2);i--)cnt+=f[i];
			else if(bb>n/2)for(int i=n;i>n-(bb-n/2);i--)cnt+=f[i];
			else for(int i=n;i>n-(cc-n/2);i--)cnt+=f[i];
			cout<<cnt<<"\n";
		} 
	}
	return 0;
}
