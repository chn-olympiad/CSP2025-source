#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+5;
int n,q,Len,L,R,sum;
string s1[MAXN],s2[MAXN];
string t1,t2,S,T;
bool check(int x) 
{ 
	int Now=0,End=-1;
	for(int i=0;i<s1[x].size();++i) 
	{ 
		if(s1[x][i]==S[Now]&&s2[x][i]==T[Now]) ++Now;
		else Now=0;
		if(Now==0&&s1[x][i]==S[Now]&&s2[x][i]==T[Now]) ++Now;
		if(Now==S.size()) 
		{ 
			End=i;
			break;
		} 
	} 
	if(End==-1||R-Now<0||R-Now+s1[x].size()-1>Len) return false;
	for(int i=0;i<s1[x].size();++i) 
		if(t1[R-Now+i]!=s1[x][i]||t2[R-Now+i]!=s2[x][i]) return false;
	return true;
} 
int main() 
{ 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i) 
		cin>>s1[i]>>s2[i];
	while(q--)
	{ 
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) { 
			cout<<"0\n";
			continue;} 
		Len=t1.size();
		L=R=-1;
		S=T="";
		sum=0;
		for(int i=0;i<Len;++i) 
		{ 
			if(t1[i]!=t2[i]) 
			{ 
				R=i;
				if(L==-1) L=i;
			} 
		} 
		for(int i=L;i<=R;++i) S=S+t1[i],T=T+t2[i];
		for(int i=1;i<=n;++i) 
			if(check(i)) ++sum;
		cout<<sum<<"\n"; 
	} 

	return 0;
} 
