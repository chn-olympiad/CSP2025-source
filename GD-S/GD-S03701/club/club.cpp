#include<bits/stdc++.h>
using namespace std;
int n,t,a[5][200010],s,maa[200010],mii[200010],id[200010],g[200010],m[5],f[5];
bool cp(int x,int y){
	return x>y;
}
bool cmp(int x,int y){
	if(maa[id[x]]!=maa[id[x]])
		return a[maa[id[x]]][id[x]]>a[maa[id[y]]][id[y]];
	return a[maa[id[x]]][id[x]]+a[mii[id[y]]][id[y]]>a[mii[id[x]]][id[x]]+a[maa[id[y]]][id[y]];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		f[1]=f[2]=f[3]=1;
		m[1]=m[2]=m[3]=0;
		s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0)
				f[2]=0;
			if(a[3][i]!=0)
				f[3]=0;
			if(a[1][i]!=0)
				f[1]=0;
			int ma=max(a[1][i],max(a[2][i],a[3][i])),mi=min(a[1][i],min(a[2][i],a[3][i]));
			g[i]=ma;
			id[i]=i;
			if(ma==a[1][i])
			{
				maa[i]=1;
				if(mi==a[2][i])
					mii[i]=3;
				else
					mii[i]=2;
			}
			else if(ma==a[2][i])
			{
				maa[i]=2;
				if(mi==a[1][i])
					mii[i]=3;
				else
					mii[i]=1;
			}
			else
			{
				maa[i]=3;
				if(mi==a[1][i])
					mii[i]=2;
				else
					mii[i]=1;
			}
		}
		int e=0;
		for(int i=1;i<=3;i++)
			e+=f[i];
		if(e==2)
		{
			for(int i=1;i<=3;i++)
				if(f[i]==0)
				{
					e=i;
					break;
				}
			sort(a[e]+1,a[e]+n+1,cp);
			for(int i=1;i<=n/2;i++)
				s+=a[e][i];
			cout<<s<<endl;
			continue;
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(m[maa[id[i]]]>=n/2)
				s+=a[mii[id[i]]][id[i]];
			else
			{
				m[maa[id[i]]]++;
				s+=a[maa[id[i]]][id[i]];
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
