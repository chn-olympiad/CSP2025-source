#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string a[200005],b[200005];
string s1,s2;
int l1,l2,bj;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s1>>s2;
		l1=s1.size();
		l2=s2.size();
		for(int j=1;j<=n;j++)
		{
			string t=s1,t2=s2;
			bj=s1.find(a[j]);
			int bjj=0;
			for(int k=0;k<bj;k++)
				if(s1[k]!=s2[k]) {bjj=1;break;}
			if(bjj) continue;	
			if(bj!=0)
			{
				t.erase(0,bj);
				t2.erase(0,bj);	
			}
			while(bj>=0)
			{
				if(t==""||t2=="") break;
				t.erase(0,a[j].size());
				t=b[j]+t;
				if(t==t2) ans++;
				else break;
				t.erase(0,a[j].size());
				t2.erase(0,a[j].size());
				bj=t.find(a[j]);
			}
//			cout<<bj<<" ";
			
//			t=
//			for(int k=0;k<a[j].size();k++)
//			{
//				t[bj+k]=b[j][k];
//			}
			
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
