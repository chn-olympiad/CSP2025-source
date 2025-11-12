#include <bits/stdc++.h>
#define int long long
using namespace std;

string s1[2000];
string s2[2005];
int ans=0;
signed main(){
	    freopen("replace.in","r",stdin);
    freopen("replace","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i];cin>>s2[i];
	}
	while(q--){
	string s,e;
	cin>>s;cin>>e;
	int len=s.length();
	ans=0;
	//cout<<q<<'\n';
		for(int i=0;i<len;i++)
		{
			//cout<<"xxx";
			for(int j=1;j<=n;j++)
			{
				bool uuu=1;int lenk=s1[j].length();
				if(i+lenk<len){			
				for(int k=0;k<lenk;k++)
				{
					//cout<<k<<' ';
					if(!(s1[j][k]==s[i+k]&&s2[j][k]==e[i+k])){
						uuu=0;
					break;
					}
					
				}
				if(uuu) ans++;
			}
			}
		}
		cout<<ans<<'\n';
		
	}
	
	return 0;
}
