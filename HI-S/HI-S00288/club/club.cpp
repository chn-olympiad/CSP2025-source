#include<bits/stdc++.h> 
using namespace std;
long long n,t,i,a[110000],b[110000],c[110000],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>=0)
	{
		t--;
		cin>>n;
		ans=0;
		for(i=1;i<=n;i++)
		{
			a[i]='\0';
			b[i]='\0';
			c[i]='\0';
			cin>>a[i]>>b[i]>>c[i];
			t=max(a[i],b[i]);
			t=max(t,c[i]);
			ans+=t;
		}
		cout<<ans<<endl;
	}
	return 0;
}
