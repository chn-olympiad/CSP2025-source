#include<bits/stdc++.h>
using namespace std;
int a[15][100005],b[1000005],maxc[5][100005];
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	int t,n,m,ans=0;
	cin>>t;
	while(t!=0)
	{
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			int a1=0,a2=0,a3=0;
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			b[i]=max(a[1][i],a[2][i]);
			b[i]=max(b[i],a[3][i]);
			if(b[i]==a[1][i]&&a1<=m&&a1+a2+a3<=n)
			{
				a1++;
				ans+=b[i];
				a[1][i]=0;
				a[2][i]=0;
				a[3][i]=0;
				b[i]=max(a[1][i],a[2][i]);
				b[i]=max(b[i],a[3][i]);	
			}
			else if(b[i]==a[2][i]&&a2<=m&&a1+a2+a3<=n)
			{
				a2++;
				ans+=b[i];
				a[1][i]=0;
				a[2][i]=0;
				a[3][i]=0;
				b[i]=max(a[1][i],a[2][i]);
				b[i]=max(b[i],a[3][i]);	
			}	
			else if(b[i]==a[3][i]&&a3<=m&&a1+a2+a3<=n)
			{
				a3++;
				ans+=b[i];
				a[1][i]=0;
				a[2][i]=0;
				a[3][i]=0;
				b[i]=max(a[1][i],a[2][i]);
				b[i]=max(b[i],a[3][i]);	
			}
		}
		cout<<ans<<endl;
			ans=0;
		t--;
	}
	return 0;
}
