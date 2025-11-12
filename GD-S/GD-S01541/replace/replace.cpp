#include<bits/stdc++.h>
using namespace std;
#define ll long long
	int n,q,c[200002],L,cn1[5000002],cn0[5000002];
	string s1[200002],s2[200002],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();int c1,c2;L=max(L,len);
		for(int j=0;j<len;j++){
			if(s1[i][j]=='b')c1=j;
			if(s2[i][j]=='b')c2=j;
		}
		c[i]=c2-c1;
	}
	for(int i=1;i<=5000000;i++){
		if(c[i]>=0)cn1[c[i]]++;
		else cn0[0-c[i]]++;
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.size(),lenn=t2.size();int c1,c2;
		if(len!=lenn){
			cout<<0<<endl;continue;
		}
		for(int j=0;j<len;j++){
			if(t1[j]=='b')c1=j;
			if(t2[j]=='b')c2=j;
		}
		int C=c2-c1;
		if(C>=0)cout<<cn1[C]<<endl;
		else cout<<cn0[0-C]<<endl;
	}
	
	return 0;
}
