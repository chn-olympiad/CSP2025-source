#include<bits/stdc++.h>
using namespace std;
int n,q;
struct g2{
	int cd;
	string h1;
	string h2;
};
struct g1{
	vector<g2>cc;
};
string s1,s2,t1,t2;
map<string,string>m1;
map<string,g1>m2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		m1[s1]=s2;
		string df1="",df2="";
		int x1=0,x2=s1.size()-1;
		for(;x1<s1.size(),s1[x1]==s2[x1];x1++){}
		for(;x2>=0,s1[x2]==s2[x2];x2--){}
		if(x2-x1+1<=0) continue;
		df1=s1.substr(x1,x2-x1+1);
		df2=s2.substr(x1,x2-x1+1);
		m1[df1]=df2;
		m2[df1+df2].cc.push_back({x2-x1+1,s1,s2});
	}
	while(q--)
	{
		cin>>t1>>t2;
		int ss=0;
		if(t1.size()!=t2.size()) cout<<0<<endl;
		else
		{
			string df1="",df2="";
			int x1=0,x2=t1.size()-1;
			for(;x1<t1.size(),t1[x1]==t2[x1];x1++){}
			for(;x2>=0,t1[x2]==t2[x2];x2--){}
			df1=t1.substr(x1,x2-x1+1);
			df2=t2.substr(x1,x2-x1+1);
			if(m1[df1]==df2)
			{
				for(int i=0;i<m2[df1+df2].cc.size();i++)
				{
					if(m2[df1+df2].cc[i].cd>t1.size()) continue;
					int p1=t1.find(m2[df1+df2].cc[i].h1,0);
					int p2=t2.find(m2[df1+df2].cc[i].h2,0);
					if(p1!=-1&&p2!=-1&&p1==p2)
					{
						ss++;
					}
				}
			}
			cout<<ss<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
