#include<bits/stdc++.h>
using namespace std;
struct node
{
	string a;
	string b;
} sk[1000005];
int n,m;
int f(string t1,string t2)
{
	int ans=0;
	int l=0; for(int i=0;i<t1.size();i++)if(t1[i]!=t2[i]){l=i;break;}
	int r=0; for(int i=t1.size()-1;i>=0;i--)if(t1[i]!=t2[i]){r=i;break;}
	string s,c;for(int i=l;i<=r;i++){s+=t1[i];c+=t2[i];}
	for(int i=1;i<=n;i++)
	{
		int fl=0;
		string k=sk[i].a;
		string p=sk[i].b;
		for(int j=0;j<t1.size();j++)
			if(t1[j]==k[0]){
				int u=1;
				for(int l=0;l<k.size();l++)if(t1[j+l]!=k[l]){u=0;break;}
				if(u){fl=1;break;}
			}	
		if(!fl) continue;
		int ll=0; for(int i=0;i<k.size();i++)if(k[i]!=p[i]){ll=i;break;}
		int rr=0; for(int i=k.size()-1;i>=0;i--)if(k[i]!=p[i]){rr=i;break;}
		string s1,c1;for(int i=ll;i<=rr;i++){s1+=k[i];c1+=p[i];}
		if(s==s1&&c==c1) ans++;
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>sk[i].a>>sk[i].b;
	while(m--)
	{
		string t1;
		string t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		cout<<0<<"\n";
		else
		cout<<f(t1,t2)<<"\n";
	}
	return 0;	
} 
