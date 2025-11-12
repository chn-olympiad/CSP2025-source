# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N = 101000;
ll n,q;string s[N][2];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		string t0i,t1i,t,t2;
		cin>>t0i>>t1i;
		ll Ans=0;
		if(t0i.size()!=t1i.size()){cout<<0<<endl;continue;}
		for(int l=0;t0i[l];l++){
		if(l>0){
		t+=t0i[l-1];t2+=t1i[l-1];
		if(t!=t2)continue;
		}
		for(int r=l;t0i[r];r++)
		{
		string sb1,sb2;
		for(int i=l;i<=r;i++)sb1+=t0i[i],sb2+=t1i[i];
		bool fg=0;
		for(int i=r+1;t0i[i];i++)
		if(t0i[i]!=t1i[i]){fg=1;break;}
		if(fg)continue;
		for(int i=1;i<=n;i++)
		if(sb1==s[i][0] && sb2==s[i][1])
		Ans++;
		}
		}
		
		cout<<Ans<<endl;
	}
	return 0;
}