#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,len[200001];
string s[200001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].length();
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		int l1=t1.length(),l2=t2.length(),l=1e9,r=0;
		if(l1!=l2){cout<<0<<'\n';continue;}
		for(int i=1;i<=l1;i++)if(t1[i-1]!=t2[i-1])l=min(l,i),r=max(r,i);
		for(int i=1;i<=l;i++){
			for(int k=1;k<=n;k++){
				if((i+len[k]-1)>l1||(i+len[k]-1)<r)continue;
				int flag=1;
				for(int j=1;j<=len[k];j++)
					if(s[k][0][j-1]!=t1[i+j-2]||s[k][1][j-1]!=t2[i+j-2]){
						flag=0;
						break;
					}
				ans+=flag;
			}
		}
		cout<<ans<<'\n';
	}
	
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a



 */