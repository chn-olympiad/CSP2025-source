#include<bits/stdc++.h>
#define ULL unsigned long long 
#define P 131

using namespace std;

const int N=2e5+100,M=5e6+100;

int n,q;
string s1,s2;
ULL hsh1[N],hsh2[N];
ULL mi[M];
ULL hash_t1[M],hash_t2[M];
set<ULL> A,B;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	mi[0]=1;
	for(int i=1;i<=M-10;i++) mi[i]=mi[i-1]*P;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		for(int j=1;j<=s1.size();j++)
			hsh1[i]=hsh1[i]*P+s1[j-1],hsh2[i]=hsh2[i]*P+s2[j-1];
		A.insert(hsh1[i]),B.insert(hsh2[i]);
	}
	while(q--)
	{
		int ans=0;
		string t1,t2;
		
		cin>>t1>>t2;
		
		int siz=t1.size(); 
		for(int i=1;i<=siz;i++)
			hash_t1[i]=hash_t1[i-1]*P+t1[i-1],hash_t2[i]=hash_t2[i-1]*P+t2[i-1];
		
		for(int i=1;i<=siz;i++)
		{
			if(hash_t1[i-1]!=hash_t2[i-1]) continue;
			for(int len=1;i+len-1<=siz;len++)
			{
				if(hash_t1[siz]-hash_t1[i+len-1]*mi[siz-i-len+1]!=hash_t2[siz]-hash_t2[i+len-1]*mi[siz-i-len+1])	continue;
				ULL org_in=hash_t1[i+len-1],org_out=hash_t2[i+len-1];
				if(A.find(hash_t1[i+len-1]-hash_t1[i-1]*mi[len])==A.end()) continue;
				if(B.find(hash_t2[i+len-1]-hash_t2[i-1]*mi[len])==B.end()) continue;
				for(int j=1;j<=n;j++)
					if(hsh1[j]+hash_t1[i-1]*mi[len]==org_in && hsh2[j]+hash_t2[i-1]*mi[len]==org_out)
						ans++;
			}
		}	
		cout<<ans<<"\n";
	}
	return 0;
}