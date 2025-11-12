#include <bits/stdc++.h>
using namespace std;

int n,q,ans;
string ty,te,cnt;
struct node
{
	string dy,de;
}s[200005];
int pd(int k)
{
	string z=s[k].dy;
	int j,q,len=z.size(),llen=ty.size();
	for(int i=0; i<llen; i++)
	{
		j=i;
		q=0;
		while(ty[j] == s[k].dy[q] && q < len)
		{
			j++;
			q++;
		}
		
		if(q == len)
			return i;
	}
	
	return -1;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s[i].dy>>s[i].de;
		
	while(q--)
	{
		ans=0;
		cin>>ty>>te;
		for(int i=1; i<=n; i++)
		{
			int k=pd(i);
			if(k != -1)
			{
				cnt="";
				int len=ty.size();
				for(int j=0; j<len; j++)
				{
					if(j != k)
						cnt+=ty[j];
					else
					{
						cnt+=s[i].de;
						j+=s[i].de.size()-1;
					}
				}

				if(cnt == te)
					ans++;
			}	
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
