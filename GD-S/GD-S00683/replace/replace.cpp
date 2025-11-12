#include<bits/stdc++.h>
#define N 2005
using namespace std;
int n,q,ans,pre[N];
string u,v,s[N],t[N];
vector<int>t1,t2,kmp1[N],kmp2[N];
void getkmp1(int x,string s){
	kmp1[x].resize(s.size()+5,0);
	for(int i=2,j=0;i<s.size();i++){
		while(j&&s[i]!=s[j+1]) j=kmp1[x][j];
		if(s[i]==s[j+1]) j++;
		kmp1[x][i]=j;
	}
}
void getkmp2(int x,string s){
	kmp2[x].resize(s.size()+5,0);
	for(int i=2,j=0;i<s.size();i++){
		while(j&&s[i]!=s[j+1]) j=kmp2[x][j];
		if(s[i]==s[j+1]) j++;
		kmp2[x][i]=j;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s[i]>>t[i],
		getkmp1(i,s[i]=" "+s[i]),
		getkmp2(i,t[i]=" "+t[i]);
	while(q--){
		cin>>u>>v;
		if(u.size()!=v.size())
			{puts("0");continue;}
		u=" "+u,v=" "+v,ans=0;
		for(int i=1;i<=u.size();i++)
			pre[i]=pre[i-1]+(u[i]!=v[i]);
		for(int i=1;i<=n;i++){
			t1.clear(),t2.clear();
			for(int j=1,k=0;j<u.size();j++){
				while(k&&u[j]!=s[i][k+1]) k=kmp1[i][k];
				if(u[j]==s[i][k+1]) k++;
				if(k==s[i].size()-1)
					k=kmp2[i][k],
					t1.emplace_back(j);
			}
			for(int j=1,k=0;j<v.size();j++){
				while(k&&v[j]!=t[i][k+1]) k=kmp2[i][k];
				if(v[j]==t[i][k+1]) k++;
				if(k==t[i].size()-1)
					k=kmp2[i][k],
					t2.emplace_back(j);
			}
			for(int p1=0,p2=0;p1<t1.size()&&p2<t2.size();){
				while(p1<t1.size()&&t1[p1]<t2[p2]) p1++;
				while(p2<t2.size()&&t1[p1]>t2[p2]) p2++;
				if(t1[p1]==t2[p2])
					ans+=pre[t1[p1++]]-pre[t2[p2++]-s[i].size()+1]==pre[u.size()];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
