#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
long long n,q;
string a[200010],b[200010];
int main(){
	freopen("repalce.in","r",stdin);
	freopen("repalce.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			long long st=0;
			while(x.find(a[i],st)>=0&&x.find(a[i],st)<x.size())
			{
				st=x.find(a[i],st);
				string z=x;
				z=z.replace(st,a[i].size(),b[i]);
				if(z==y) ans++;
				st++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
