#include<bits/stdc++.h>
using namespace std;
int n,q,ans,cnt;
string s[200001][3],t[3],a,b,c,d,e;
bool z(int k){
	a=t[1],b=s[k][1],c=s[k][2],d=t[2],cnt=0;
	if(a.size()<b.size())return 0;
	int i,j;
	for(i=0;i<a.size()-b.size()+1;i++)
		if(a.substr(i,b.size())==b){
			e=a;
			for(j=i;j<i+b.size();j++)e[j]=c[j-i];
			if(e==d)cnt++;
		}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i;
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		ans=0;
		cin>>t[1]>>t[2];
		for(i=1;i<=n;i++)
			if(z(i))ans+=cnt;
		cout<<ans;
	}
	return 0;
}
