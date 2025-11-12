#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
using namespace std;
int x,y[1100],ans,a;
int main()
{
	peropen("number.in","r",stdin);
	peropen("number.out","w",stdout);
	cin>>x; 
	for(int i=1;i<=x;i++)  cin>>y[i];
	for(int i=1;i<=x;i++)
	{
		if(y[i]>y[i+1]-y[i+2]&&y[i]<y[i+1]+y[i+2]) ans++;
	}
	for(int i=1;i<=x-3;i++)
	{
		if(x-i>3)
		{
			a=x%x-1;
			ans=ans+a;
		}
	}
	cout<<ans<<endl;
	return 0;
}
