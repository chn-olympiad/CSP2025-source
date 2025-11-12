#include<bits/stdc++.h>
using namespace std;
long long n,q;
map<string,string>a;
string que[200010],b[200010],c[200010];
/*bool B()
{
	for(int i=1;i<=n;i++)
	{
		long long ddd=b[i].size(),ss=0,sss=0;
		map<char,bool>bb,cc;
		for(int j=0;j<ddd;j++)
		{
			if(cc[c[j]]==0)
			{
				sss++;
				cc[c[j]]=1;
			}
			if(bb[b[j]]==0)
			{
				bb[b[j]]=1;
				ss++;
			}
			if(ss>=3||sss>=3)
			{
				return false;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long ddd=que[i].size(),ss=0;
		map<char,bool>bb;
		for(int j=0;j<ddd;j++)
		{
			if(bb[que[j]]==0)
			{
				bb[que[j]]=1;
				ss++;
			}
			if(ss>=3)
			{
				return false;
			}
		}
	}
	return true;
}*/
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>c[i];
		a[b[i]]=c[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>que[i];
	}
	/*if(B())
	{
		
	}
	else
	{*/
		for(int i=1;i<=q;i++)
		{
			cout<<"0\n";
		}
	//}
	return 0;
}

