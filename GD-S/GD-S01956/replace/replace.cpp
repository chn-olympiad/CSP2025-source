#include<bits/stdc++.h>
using namespace std;
int n,q,cox[200005],coy[200005];
string a1[200005],a2[200005],t1,t2;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int bj=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>a2[i];
		int x=a1[1].size();
		for(int j=0;j<x;j++)
		{
			if(a1[i][j]!='a'&&a1[i][j]!='b')
			{
				bj=1;
			}
			if(a2[i][j]!='a'&&a2[i][j]!='b')
			{
				bj=1;
			}
		}
	}
	if(bj==0)
	{
		int x=0,y=0;
		for(int i=1;i<=n;i++)
		{
			int x=a1[i].size();
			int xx=0,yy=0;
			for(int j=0;j<x;j++)
			{
				if(a1[i][j]=='b')
				{
					xx=j;
				}
				if(a2[i][j]=='b')
				{
					yy=j;
				}
			}
			cox[i]=xx;
			coy[i]=yy;	
			//cout<<xx<<"w"<<yy<<endl;
		}
		for(int i=1;i<=q;i++)
		{
			cin>>t1>>t2;
			int x=t1.size(),y=t2.size();
			if(x!=y) 
			{
				cout<<"0"<<endl;
				continue;
			}
			int bx=0,by=0;
			for(int j=0;j<x;j++)
			{
				if(t1[j]=='b') bx=j;
				if(t2[j]=='b') by=j;
			}
		//	cout<<" "<<bx<<"w"<<by<<" ";
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				if(cox[j]<=bx&&coy[j]<=by&&a1[j].size()-cox[j]<=x-bx&&a2[j].size()-coy[j]<=y-by)
				{
					if(bx-by==cox[j]-coy[j]) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cin>>t1>>t2;
			int x=t1.size(),y=t2.size();
			if(x!=y) 
			{
				cout<<"0"<<endl;
				continue;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
} 
