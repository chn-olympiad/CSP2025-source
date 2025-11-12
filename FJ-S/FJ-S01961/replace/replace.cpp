#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,q;
string s1[N],s2[N];
vector<int> p[N];

void pre(){
	for(int l=1;l<=n;l++)
	{
		int lim=s1[l].size();
		p[l].resize(lim+3);
		p[l][0]=0;
		for(int i=1,j=0;i<=lim;i++)
		{
			while(j>0&&s1[i]!=s1[j])
				j=p[l][j-1];
			if(s1[i]==s1[j])
				j++;
			p[l][i]=j;
		}
	}
}

int kmp(int l,string t1,string t2){
	int lim=t1.size(),len=s1[l].size();
	int res=0;
	for(int i=0,j=0;i<lim;i++)
	{
		while(j>0&&t1[i]!=s1[l][j])
			j=p[l][j-1];
		if(t1[i]==s1[l][j])
			j++;
		if(j>=len)
		{
			string tmp=t1;
			if(tmp.replace(i-len+1,len,s2[l])==t2)
				res++;
		}
	}
	return res;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	
	pre();
	
	string t1,t2;
	for(;q;q--)
	{
		cin>>t1>>t2;
		bool e=1;
		if(t1.size()!=t2.size())
			e=0;
		int res=0;
		for(int i=1;i<=n&&e;i++)
			res+=kmp(i,t1,t2);
		cout<<res<<endl;
	}
	return 0;
}
