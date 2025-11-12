#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long n,q,k,l,sum;
string s1[N],s2[N],st,t1,t2,ss;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;sum=0;
		for(int j=1;j<=n;j++)
		{
			k=t1.find(s1[j],0);
			l=s1[j].size();
			while(k!=-1)
			{
				ss="";
				ss=t1.substr(0,k)+s2[j]+t1.substr(k+l,t1.size()-(k+l));
				if(ss==t2) sum++; 
				k=t1.find(s1[j],k+1);
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}



