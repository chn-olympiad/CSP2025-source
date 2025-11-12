#include<bits/stdc++.h>
using namespace std;
struct club(){
	int pai;
	int nextmin;	
}p[10010];
int n,fil[10010],sel[10010],thl[10010],sum,a,b,c,k[10010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int T=0;T<t;T++)
	{
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>fil[i]>>sel[i]>>thl[i];
			k[i]=max(fil[i],max(sel[i],thl[i]));
			if(k[i]==fil[i]) p[i]=1,a++;
			if(k[i]==sel[i]) p[i]=2,b++;
			if(k[i]==thl[i]) p[i]=3,c++;
			sum+=k[i];
		}
		int bz=n/2;
		cout<<sum<<endl;
	}
	return 0;
}
