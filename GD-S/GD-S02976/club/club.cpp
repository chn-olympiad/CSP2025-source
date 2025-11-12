#include<bits/stdc++.h>
using namespace std;
int T;
int n,a,b,c;
int s[120000][2];
int l[120000],ll[120000];
int t[4];
int dui[210000][2],cnt;
int dui1[210000][2],cnt1;
void duipop()
{
	dui[1][0]=10000000;
	dui[1][1]=10000000;
	int nw=1,nt;
	while(1)
	{
		if(dui[nw<<1][1]>dui[(nw<<1)+1][1])
		nt=nw<<1;
		else
		nt=(nw<<1)+1;
		if(nt>cnt)
		break;
		if(dui[nw][1]>dui[nt][1])
		{
			swap(dui[nt][0],dui[nw][0]);
			swap(dui[nt][1],dui[nw][1]);
			nw=nt;
		}
		else
		break;
	}
	cnt--;
}
void duipush(int x,int y)
{
	++cnt;
	dui[cnt][0]=x;
	dui[cnt][1]=y;
	int nw=cnt;
	while(nw^1)
	{
		if(dui[nw/2][1]>dui[nw][1])
		{
			swap(dui[nw/2][0],dui[nw][0]);
			swap(dui[nw/2][1],dui[nw][1]);
			nw/=2;
		}
		else
			break;
	}
}
void dui1pop()
{
	dui1[1][0]=10000000;
	dui1[1][1]=10000000;
	int nw=1,nt;
	while(1)
	{
		if(dui1[nw<<1][1]>dui1[(nw<<1)+1][1])
			nt=nw<<1;
		else
			nt=(nw<<1)+1;
		if(nt>cnt1)
			break;
		if(dui1[nw][1]>dui1[nt][1])
		{
			swap(dui1[nt][0],dui1[nw][0]);
			swap(dui1[nt][1],dui1[nw][1]);
			nw=nt;
		}
		else
		break;
	}
	cnt1--;
}
void dui1push(int x,int y)
{
	++cnt1;
	dui1[cnt1][0]=x;
	dui1[cnt1][1]=y;
	int nw=cnt;
	while(nw^1)
	{
		if(dui1[nw/2][1]>dui1[nw][1])
		{
			swap(dui1[nw/2][0],dui1[nw][0]);
			swap(dui1[nw/2][1],dui1[nw][1]);
			nw/=2;
		}
		else
			break;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			if((a>b||a==b)&&(a>c||a==c))
				s[i][0]=a,l[i]=1;
			else if((b>a||b==a)&&(b>c||b==c))
				s[i][0]=b,l[i]=2;
			else 
				s[i][0]=c,l[i]=3;
			t[l[i]]++;
			
			if(a==s[i][0]&&b==max(b,c))
			s[i][1]=b,ll[i]=2;
			else if(a==s[i][0]&&c==max(b,c))
			s[i][1]=c,ll[i]=3;
			
			else if(b==s[i][0]&&a==max(a,c))
			s[i][1]=a,ll[i]=1;
			else if(b==s[i][0]&&c==max(a,c))
			s[i][1]=c,ll[i]=3;
			
			if(c==s[i][0]&&b==max(a,b))
			s[i][1]=b,ll[i]=2;
			if(c==s[i][0]&&a==max(a,b))
			s[i][1]=a,ll[i]=1;
			
			s[i][1]=min(a,b)+min(b,c)-min(a,min(b,c));
			if(s[i][1]==min(a,min(b,c)))
			s[i][1]=min(a,c);
		}
		int zha=0,num;
		for(int i=1;i<=3;i++)
		{
			if(t[i]>n/2)
			{
				zha=i;
				num=t[i];
				break;
			}
			t[i]=0;
		}
		int ans=0;
		if(zha==0)
		{
			for(int i=1;i<=n;i++)
				ans+=s[i][0];
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(l[i]==zha)
			{
				duipush(i,s[i][0]-s[i][1]);
				dui1push(i,s[i][0]);
			}
		}
		while(num>n/2)
		{
			//cout<<dui1[1][1]<<" "<<dui[1][1]<<" "<<dui1[1][0]<<" "<<s[dui1[1][0]][1]<<"\n";
			if(dui1[1][1]-dui[1][1]>s[dui1[1][0]][1])
			{
				
				l[dui[1][0]]=ll[dui[1][0]];
				duipop();
				num--;
			}
			else
			{
				l[dui1[1][0]]=ll[dui1[1][0]];
				dui1pop();
				num--;
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			ans+=dui[1][1];
			duipop();
		}
		for(int i=1;i<=n;i++)
		{
			if(l[i]^zha)
			ans+=s[i][0];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
